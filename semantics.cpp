#include "semantics.hpp"

int sem_errors = 0;
int yy_sem_error(std::string msg, int row_num = 0, int col_num = 0)
{
	sem_errors++;
	// fprintf(stderr, "\n\033[1;36mLine %d:%d:\033[0m \033[1;31merror:\033[0m Unexpected Token \033[1;31m%s\033[0m",
	//         yylineno, cur_char, yytext);
	std::cerr << CYAN_COLOR << "Line " << row_num << ":" << col_num << ":" << RED_COLOR << " error:" << RESET_COLOR << msg << std::endl;
	// std::cerr <<"\t\t"<<row_num<<" | "<<"\t\t"<<RED_COLOR<<" error:"<<RESET_COLOR<< msg << std::endl;
	return 0;
}

int yy_sem_warning(const std::string msg)
{

	std::cerr << msg << std::endl;
	return 0;
}

// matches list initializer against a struct
bool match_list_init_struct(ASTNode *node,
							Struct *struct_info,
							SymbolTable *current,
							SymbolTable *global)
{
	if (node->children.size() != struct_info->members.size())
	{
		std::string message = "Struct " + RED_COLOR + struct_info->name + RESET_COLOR + " expects " + YELLOW_COLOR +
							  std::to_string(struct_info->members.size()) + RESET_COLOR + " members but got " + RED_COLOR +
							  std::to_string(node->children.size()) + RESET_COLOR;
		yy_sem_error(message);
		return false;
	}

	for (int i = 0; (long unsigned int)i < node->children.size(); i++)
	{
		DataType member_type = struct_info->members[i].type;
		if (member_type.reference && node->children[i]->kind == list_init)
		{
			std::string message = "Struct " + RED_COLOR + struct_info->name + RESET_COLOR + " expects member " + YELLOW_COLOR +
								  std::to_string(i) + RESET_COLOR + " to be a reference";
			yy_sem_error(message);
			return false;
		}

		if (node->children[i]->kind != list_init)
		{
			resolve_expression(node->children[i], current, global);
		}
		else if (!match_list_init(node->children[i], struct_info->members[i].type, current, global))
		{
			return false;
		}
		DataType child_type = node->children[i]->type;

		if (member_type.type != struct_t && member_type != child_type)
		{
			std::string message = "Struct " + RED_COLOR + struct_info->name + RESET_COLOR + " expects member " + YELLOW_COLOR +
								  std::to_string(i) + RESET_COLOR + " of type " + YELLOW_COLOR + member_type.to_string() + RESET_COLOR +" but got " + RED_COLOR + child_type.to_string() + RESET_COLOR;
			yy_sem_error(message);
			return false;
		}
		if (member_type.type == struct_t && member_type.name != child_type.name)
		{
			std::string message = "Struct " + RED_COLOR + struct_info->name + RESET_COLOR + " expects member " + YELLOW_COLOR +
								  std::to_string(i) + RESET_COLOR + " of type " + YELLOW_COLOR + member_type.name + RESET_COLOR + " but got " +
								  YELLOW_COLOR + child_type.name + RESET_COLOR;
			yy_sem_error(message);
			return false;
		}
	}

	node->type = DataType(struct_t, struct_info->name);

	return true;
}

// Checks if a function call is valid
bool check_valid_function_call(ASTNode *node,
							   SymbolTable *current,
							   SymbolTable *global,
							   Function *func)
{

	if (node->children.size() != func->param_list.size())
	{

		std::string message = "Function " + node->name + " expects " +
							  std::to_string(func->param_list.size()) + " arguments but got " +
							  std::to_string(node->children.size());
		yy_sem_error(message);
		return false;
	}

	for (int i = 0; (long unsigned int)i < node->children.size(); i++)
	{
		DataType param_type = func->param_list[i].type;
		if (param_type.reference && node->children[i]->kind == list_init)
		{
			std::string message = "Function " + node->name + " expects argument " +
								  std::to_string(i) + " to be a reference";
			yy_sem_error(message);
			return false;
		}
		if (node->children[i]->kind != list_init)
		{
			resolve_expression(node->children[i], current, global);
		}
		else
		{
			if (!match_list_init(node->children[i], param_type, current, global))
			{
				return false;
			}
		}
		DataType arg_type = node->children[i]->type;

		if (param_type != arg_type)
		{
			std::string message = "Function " + node->name + " expects argument " +
								  std::to_string(i) + " of type " + param_type.to_string() +
								  " but got " + arg_type.to_string();
			yy_sem_error(message);
			return false;
		}
	}
	return true;
}

// Function to resolve the base cases of the expression like a chain of identifiers, literal, variable, array element, function call
DataType retrieveType(ASTNode *node, SymbolTable *current, SymbolTable *global)
{

	if (node->kind == array_element)
	{

		SymbolTableEntry *e = current->getEntryNested(node->name);
		if (e == NULL)
		{

			std::string message = "Variable " + node->name + " not declared";
			yy_sem_error(message);
			return error_type;
		}

		if (e->type != variable)
		{

			std::string message =
				"Variable " + node->name + " already declared as a " + entry_type_strings[e->type];
			yy_sem_error(message);
			return error_type;
		}

		DataType type = ((Variable *)(e->ptr))->type;

		for (auto child : node->children)
		{

			if (child->kind == literal &&
				(stoi(child->name) >= type.ndims.back() || stoi(child->name) < 0))
			{
				std::string message = "Array index out of bounds";
				yy_sem_error(message);
				return error_type;
			}

			if (child->kind != literal)
			{
				resolve_expression(child, current, global);
				if (child->type != DataType(int_t))
				{
					std::string message = "Array index must be an integer";
					yy_sem_error(message);
					return error_type;
				}
			}
			type.ndims.pop_back();
		}
		node->type = type;
		return type;
	}
	else if (node->kind == variable_t)
	{

		SymbolTableEntry *e = current->getEntryNested(node->name);
		if (e == NULL)
		{

			std::string message = "Variable " + node->name + " not declared";
			yy_sem_error(message);
			return error_type;
		}

		if (e->type != variable)
		{

			std::string message =
				"Variable " + node->name + " already declared as a " + entry_type_strings[e->type];
			yy_sem_error(message);
			return error_type;
		}

		Variable *var_entry = (Variable *)(e->ptr);
		node->type = var_entry->type;
		return var_entry->type;
	}
	else if (node->kind == literal)
	{
		return node->type;
	}
	else if (node->kind == function_call_stmt)
	{

		SymbolTableEntry *e = global->getEntry(node->name);

		if (e == NULL)
		{

			std::string message = "Function " + node->name + " not declared";
			yy_sem_error(message);
			node->type = error_type;
			return error_type;
		}

		if (e->type != function)
		{

			std::string message =
				"Function " + node->name + " already declared as a " + entry_type_strings[e->type];
			yy_sem_error(message);
			node->type = error_type;
			return error_type;
		}
		Function *func_entry = (Function *)(e->ptr);
		if (!check_valid_function_call(node->children[0], current, global, func_entry))
		{
			node->type = error_type;
			return error_type;
		}
		node->type = func_entry->return_type;
		return func_entry->return_type;
	}
	else if (node->kind == identifier_chain)
	{

		ASTNode *chain_node = node;
		ASTNode *first = node->children[0];
		ASTNode *second;
		SymbolTableEntry *e = current->getEntryNested(first->name);
		if (e == NULL)
		{
			std::string message = "Variable " + first->name + " not declared";
			yy_sem_error(message);
			return error_type;
		}

		if (e->type != variable)
		{
			std::string message =
				"Variable " + first->name + " already declared as a " + entry_type_strings[e->type];
			yy_sem_error(message);
			return error_type;
		}

		DataType t = ((Variable *)(e->ptr))->type;
		if (((Variable *)(e->ptr))->type != DataType(struct_t, t.name))
		{
			std::string message = "Variable " + first->name + " is not a struct";
			yy_sem_error(message);
			return error_type;
		}

		Struct *struct_info = (Struct *)global->getEntry(((Variable *)(e->ptr))->type.name)->ptr;
		first->type = ((Variable *)(e->ptr))->type;
		do
		{
			first = chain_node->children[0];
			second = chain_node->children[1];
			bool hap = false;

			if (second->kind == identifier_chain) // basically the left one is definitely a variable
				second = second->children[0], hap = true;

			std::vector<Variable> members = struct_info->members;
			Variable *member_info = NULL;
			for (auto member : members)
			{
				if (member.name == second->name)
				{
					member_info = &member;
					break;
				}
			}
			if (member_info == NULL)
			{ // check if a relevant member exists
				std::string message =
					"Struct " + first->name + " does not have a member " + second->name;
				yy_sem_error(message);
				return error_type;
			}

			second->type = member_info->type;

			// handle the case where it is an array element, resolve its type(can't go to symbol table here.)
			if (second->kind == array_element)
			{
				for (auto child : second->children)
				{
					resolve_expression(child, current, global);
					if (child->type != DataType(int_t))
					{
						std::string message = "Array index must be an integer";
						yy_sem_error(message);
						return error_type;
					}

					if (child->kind == literal &&
						(stoi(child->name) >= second->type.ndims.back() || stoi(child->name) < 0))
					{
						std::string message = "Array index out of bounds";
						yy_sem_error(message);
						return error_type;
					}
					second->type.ndims.pop_back();
				}
			}

			// Checks if the second one is a valid struct name
			if (second->type == DataType(struct_t, second->type.name))
			{
				struct_info = (Struct *)global->getEntry(second->type.name)->ptr;
				if (struct_info == NULL)
				{
					std::string message = "Struct " + member_info->type.name + " not declared";
					yy_sem_error(message);
					return error_type;
				}
			}
			else if (hap)
			{
				std::string message = "Member " + second->name + " is not a struct";
				yy_sem_error(message);
				return error_type;
			}
			chain_node = chain_node->children[1];

		} while (chain_node->kind == identifier_chain);

		node->type = second->type;
		return second->type;
	}
	else if (node->kind == expr_stmt)
	{
		resolve_expression(node, current, global);
		return node->type;
	}
	else
		return error_type;
}
// Function to check if the node of type initialiser_list is valid array
// Here dims is dimensions of the array in reverse(useful for popping)
// type in core type of the array
bool match_list_init_array(ASTNode *node,
						   DataType type,
						   std::vector<int> &dims,
						   int dim_number,
						   SymbolTable *current,
						   SymbolTable *global)
{
	int x = dims.back();
	// if not enough children
	if (node->children.size() != (long unsigned int)x)
	{

		std::string message = "Array dimension mismatch: Expected " + std::to_string(x) +
							  " but got " + std::to_string(node->children.size());
		yy_sem_error(message);
		return false;
	}

	for (auto child : node->children)
	{
		dims.pop_back();
		type.ndims.pop_back();
		if (dims.size() == 0)
		{
			if (type.type == struct_t && child->kind == list_init)
			{ // structs must be handled separately
				Struct *struct_info = (Struct *)global->getEntry(type.name)->ptr;
				if (!match_list_init_struct(child, struct_info, current, global))
				{
					return false;
				}
			}
			else if (child->kind == list_init)
			{ // if the type is not struct, then it should be list_init, which is an error
				std::string message = "Array dimension mismatch: Expected " +
									  std::to_string(dim_number) + " dimensions but got more";
				yy_sem_error(message);
				return false;
			}
			else
			{ // can be identifier chain, array_element, literal, first call resolve expression
				resolve_expression(child, current, global);
				// if (child->type.type != type.type || child->type.name != type.name){

				// }

				if (type.type != struct_t && child->type != type)
				{
					std::string message = "Type mismatch in array initialisation: Expected " +
										  dtype_strings[type.type] + " but got " +
										  dtype_strings[child->type.type];
					yy_sem_error(message);
					return false;
				}

				if (type.type == struct_t && child->type.name != type.name)
				{
					std::string message =
						"Type mismatch in array initialisation: Expected struct " + type.name +
						" but got " + child->type.name;
					yy_sem_error(message);
					return false;
				}
			}
		}
		else if (child->kind != list_init)
		{ // if the type is not struct, then it is other form of expression
			resolve_expression(child, current, global);
			if (child->type != type)
			{
				std::string message = "Type mismatch in array initialisation: Expected " +
									  dtype_strings[type.type] + " but got " +
									  dtype_strings[child->type.type];
				yy_sem_error(message);
				return false;
			}

			// match dims
			if (dims.size() != child->type.ndims.size())
			{
				std::string message = "Array dimension mismatch: Expected " +
									  std::to_string(dim_number) + " dimensions but got more";
				yy_sem_error(message);
				return false;
			}

			for (int i = 0; (long unsigned int)i < dims.size(); i++)
			{
				if (dims[i] != child->type.ndims[i])
				{
					std::string message = "Array dimension mismatch: Expected " +
										  std::to_string(dim_number) + " dimensions but got more";
					yy_sem_error(message);
					return false;
				}
			}
		}
		else
		{
			if (!match_list_init_array(child, type, dims, dim_number + 1, current, global))
			{
				return false;
			}
		}
		dims.push_back(x);
		type.ndims.push_back(x);
	}
	node->type = type;

	return true;
}

// Function to check if the node of type initialiser_list is valid
bool match_list_init(ASTNode *node, DataType type, SymbolTable *current, SymbolTable *global)
{

	if (type.type == struct_t && type.ndims.size() == 0)
	{
		Struct *struct_info = (Struct *)global->getEntry(type.name)->ptr;
		return match_list_init_struct(node, struct_info, current, global);
	}
	else if (type.ndims.size() == 0)
	{
		std::string message = "Type mismatch in array initialisation: Expected " +
							  dtype_strings[type.type] + " but got array";
		yy_sem_error(message);
		return false;
	}
	else
	{
		std::vector<int> dims = type.ndims;
		return match_list_init_array(node, type, dims, 0, current, global);
	}
}

// does type checks against unary operators
DataType
resolve_unary_operator(ASTNode *node, std::string op, SymbolTable *current, SymbolTable *global)
{
	if (op != "-" && op != "!")
	{ // Check if the operator is unary
		std::string message = "Operator " + op + " requires two operands";
		yy_sem_error(message);
		return error_type;
	}
	if (node->type == error_type)
	{
		return error_type;
	}

	DataType type = node->type;
	if (type.ndims.size() != 0)
	{
		std::string message = "Arrays not allowed in unary expressions";
		yy_sem_error(message);
		return error_type;
	}

	if (op == "-")
	{ // Checking valid types for unary operator
		if (type.type != int_t && type.type != float_type && type.type != long_t)
		{
			std::string message = "Type mismatch in operator " + op;
			yy_sem_error(message);
			return error_type;
		}
		return type;
	}

	// handling not operator here
	if (type.type != int_t && type.type != float_type && type.type != long_t && type.type != bool_t)
	{
		std::string message = "Type mismatch in operator " + op;
		yy_sem_error(message);
		return error_type;
	}
	return type;
}

DataType resolve_binary_operator(
	ASTNode *left, ASTNode *right, std::string op, SymbolTable *current, SymbolTable *global)
{
	if (left->type == error_type || right->type == error_type)
	{
		return error_type;
	}

	dtypes left_type = left->type.type;
	dtypes right_type = right->type.type;
	if (op == "=")
	{

		if (left->kind != variable_t && left->kind != array_element &&
			left->kind != identifier_chain)
		{
			std::string message = "Left side of " + op + " must be a lvalue";
			yy_sem_error(message);
			return error_type;
		}

		if (left->kind == variable_t && !current->checkNameNested(left->name, variable))
		{ // declare the variable implicitly with type inferred from right
			Variable *var_entry = new Variable(left->name, right->type);
			current->addVariable(left->name, var_entry);
			left->type = right->type;
		}
		else if (left->kind == variable_t && current->checkNameNested(left->name, variable))
		{

			resolve_expression(left, current, global);
		}
		else if (left->kind == variable_t && (global->getEntry(left->name) != nullptr &&
											  global->getEntry(left->name)->type != variable))
		{
			std::string message = "Variable " + left->name + " already declared as a " +
								  entry_type_strings[global->getEntry(left->name)->type];
			yy_sem_error(message);
			return error_type;
		}

		if (left->type == right->type)
			return left->type;
	}

	if (left->type.ndims.size() != 0 || right->type.ndims.size() != 0)
	{
		std::string message = "Arrays not allowed in binary expressions except assignments";
		yy_sem_error(message);
		return error_type;
	}

	if (left->type.type == struct_t || right->type.type == struct_t)
	{
		std::string message = "Structs not allowed in binary expressions except assignments";
		yy_sem_error(message);
		return error_type;
	}

	if ((op == "==") | (op == "!="))
	{
		if (left->type == right->type)
			return bool_t;
	}
	else if ((op == "+=") | (op == "-=") | (op == "*=") | (op == "/=") | (op == "%="))
	{
		if (left->kind != variable_t && left->kind != array_element &&
			left->kind != identifier_chain)
		{
			std::string message = "Left side of " + op + " must be a lvalue";
			yy_sem_error(message);
			return error_type;
		}

		// assign_checks:
		if (left_type == int_t && right_type == int_t) // handling numerical cases
			return left_type;
		else if (left_type == float_type && right_type == float_type)
			return left_type;
		else if (left_type == long_t && right_type == long_t)
			return left_type;
		else if (left_type == float_type && right_type == int_t)
			return left_type;
		else if (left_type == int_t && right_type == float_type)
			return left_type;
		else if (left_type == long_t && right_type == int_t)
			return left_type;
		else if (left_type == int_t && right_type == long_t)
			return left_type;
		else if (left_type == long_t && right_type == float_type)
			return left_type;
		else if (left_type == float_type && right_type == long_t)
			return left_type;

		if (left_type == bool_t && right_type == bool_t) // handling boolean cases
			return left_type;
		else if (left_type == bool_t && right_type == int_t)
			return left_type;
		else if (left_type == int_t && right_type == bool_t)
			return left_type;
		else if (left_type == bool_t && right_type == float_type)
			return left_type;
		else if (left_type == float_type && right_type == bool_t)
			return left_type;
		else if (left_type == bool_t && right_type == long_t)
			return left_type;
		else if (left_type == long_t && right_type == bool_t)
			return left_type;

		// handling string/char
		if (left_type == string_t && right_type == string_t && (op == "+="))
			return left_type;
		if (left_type == string_t && right_type == char_t && (op == "+="))
			return left_type;

		if (left_type == string_t && right_type == int_t &&
			(op == "+=")) // basically I can do things as worse as Javascript :()
			return left_type;
	}
	if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%")
	{

		// arith_check:
		if (left_type == int_t && right_type == int_t) // handling numerical cases
			return int_t;
		else if (left_type == float_type && right_type == float_type)
			return float_type;
		else if (left_type == long_t && right_type == long_t)
			return long_t;
		else if (left_type == float_type && right_type == int_t)
			return float_type;
		else if (left_type == int_t && right_type == float_type)
			return float_type;
		else if (left_type == long_t && right_type == int_t)
			return long_t;
		else if (left_type == int_t && right_type == long_t)
			return long_t;
		else if (left_type == long_t && right_type == float_type)
			return float_type;
		else if (left_type == float_type && right_type == long_t)
			return float_type;

		if (left_type == bool_t && right_type == bool_t) // handling boolean cases
			return int_t;
		else if (left_type == bool_t && right_type == int_t)
			return int_t;
		else if (left_type == int_t && right_type == bool_t)
			return int_t;
		else if (left_type == bool_t && right_type == float_type)
			return float_type;
		else if (left_type == float_type && right_type == bool_t)
			return float_type;
		else if (left_type == bool_t && right_type == long_t)
			return long_t;
		else if (left_type == long_t && right_type == bool_t)
			return long_t;

		// handling string/char
		if (left_type == string_t && right_type == string_t && (op == "+"))
			return string_t;
		if (left_type == string_t && right_type == char_t && (op == "+"))
			return string_t;

		if (left_type == char_t && right_type == string_t && op == "+")
			return string_t;

		if (left_type == char_t && right_type == char_t && op == "+")
			return string_t;

		if (left_type == string_t && right_type == int_t &&
			op == "+") // basically I can do things as worse as Javascript :()
			return string_t;
	}
	else if (op == "<" || op == ">" || op == "<=" || op == ">=")
	{
		if (!(left_type == int_t || left_type == float_type || left_type == long_t ||
			  left_type == bool_t))
			return error_type;

		if (!(right_type == int_t || right_type == float_type || right_type == long_t ||
			  right_type == bool_t))
			return error_type;
		return bool_t;
	}
	else if (op == "&&" || op == "||")
	{
		if (!(left_type == int_t || left_type == long_t || left_type == float_type ||
			  left_type == bool_t))
		{
			return error_type;
		}

		if (!(right_type == int_t || right_type == long_t || right_type == float_type ||
			  right_type == bool_t))
		{
			return error_type;
		}

		return bool_t;
	}

	std::string message = "Type mismatch in operator " + op;
	yy_sem_error(message);
	return error_type;
}

// TODO: annotate retrieve types and complete binary operator resolutoin
//  Function to resolve the expression
void resolve_expression(ASTNode *node, SymbolTable *current, SymbolTable *global)
{
	if (node->name == "=")
	{

		if (node->children[0]->kind == expr_stmt || node->children[0]->kind == literal)
		{
			std::string message = "Assignment requires a lvalue";

			yy_sem_error(message);
			node->type = error_type;
			return;
		}
		if (node->children[0]->kind == variable_t)
			goto expr;
	}

	if (node->kind != expr_stmt)
	{
		DataType type = retrieveType(node, current, global);
		node->type = type;
		return;
	}

	resolve_expression(node->children[0], current, global);
	if (node->children.size() < 2)
	{ // Handling Unary Operators
		node->type = resolve_unary_operator(node->children[0], node->name, current, global);
		return;
	}
expr: // label to jump to

	resolve_expression(node->children[1], current, global);
	node->type =
		resolve_binary_operator(node->children[0], node->children[1], node->name, current, global);
}

// Takes a current rule node and fills the graph_edges with the order of the tasks(directed)
bool build_order_graph(ASTNode* curRule,  std::vector<std::vector<bool>>& graph_edges, std::unordered_map<std::string, int>& task_mapping){
    std::vector<ASTNode*> children = curRule->children;

    // check both the starting and ending must not be all
    if(children.size() < 2){
        std::string message = "Order rule must have atleast two nodes";
        yy_sem_error(message);
        return false;
    }

    bool flag = false;
    for(auto child: children){
        for(auto grandchild: child->children){
            if(task_mapping.find(grandchild->name) == task_mapping.end() && grandchild->name != "all"){
                std::string message = "Task " + grandchild->name + " not declared";
                yy_sem_error(message);
                flag = true;
            }
        }
    }

    if(flag) return false;

    if(children[0]->children[0]->name == "all" && children[children.size() -1]->children[0]->name == "all"){
        std::string message = "Can't Resolve the Order due to all";
        yy_sem_error(message);
        return false;
    }

    std::vector<std::string> all_nodes;
    std::unordered_map<std::string, bool> used_nodes;
    // resolve the first all :: all nodes except those which come after it
    if(children[0]->children[0]->name == "all"){
        for(int i = 1; i < children.size(); i++){
            for(int j = 0; j < children[i]->children.size(); j++){
                used_nodes[children[i]->children[j]->name]= true;
            }
        }
        for(auto kv: task_mapping){
            if(used_nodes.find(kv.first) == used_nodes.end()){
                all_nodes.push_back(kv.first);
            }
        }

        delete children[0]->children[0];
        children[0]->children.pop_back();

        for(int i = 0; i < all_nodes.size(); i++){
            children[0]->children.push_back(new ASTNode(task_t, all_nodes[i]));
            // std::cout << "Debugging: " << all_nodes[i] << std::endl;
        }
    }

    // resolve the last all :: all nodes except those which come before it
    if(children[children.size() - 1]->children[0]->name == "all"){
        for(int i = 0; i < children.size() - 1; i++){
            for(int j = 0; j < children[i]->children.size(); j++){
                used_nodes[children[i]->children[j]->name]= true;
            }
        }
        for(auto kv: task_mapping){
            if(used_nodes.find(kv.first) == used_nodes.end()){
                all_nodes.push_back(kv.first);
            }
        }

        children[children.size() - 1]->children.pop_back();
        delete children[children.size() - 1]->children[0];
        for(int i = 0; i < all_nodes.size(); i++){
            children[children.size() - 1]->children.push_back(new ASTNode(task_t, all_nodes[i]));
        }
    }

    std::vector<int> prev_nodes;
    for(int i = 0; i < children.size(); i++){
        std::vector<int> cur_nodes;
        for(int j = 0; j < children[i]->children.size(); j++){
            cur_nodes.push_back(task_mapping[children[i]->children[j]->name]);
            // std::cout << "Debugging: " << children[i]->children[j]->name << std::endl;
        }
        for(int j = 0; j < prev_nodes.size(); j++){
            for(int k = 0; k < cur_nodes.size(); k++){
                graph_edges[prev_nodes[j]][cur_nodes[k]] = 1;
                // std::cout << "Debugging: edge between " << prev_nodes[j] << " and " << cur_nodes[k] << std::endl;
            }
        }
        prev_nodes = cur_nodes;
    }

    return true;

}

bool check_circular(int i, std::vector<std::vector<bool>>& graph_edges, std::vector<int>& visited){
    if(visited[i] == 1){
        return false;
    }
    visited[i] = 1;
    for(int j = 0; j < graph_edges.size(); j++){
        if(graph_edges[i][j]){
            if(check_circular(j, graph_edges, visited)){
                return true;
            }
        }
    }
    return false;
}

void resolve_order_block(ASTNode *node, TaskGroup *taskGroupEntry, SymbolTable *global, std::unordered_set<std::string> &identifiers, std::vector<std::string> &task_names, std::unordered_map<std::string, int> &task_mapping)
{
	std::vector<ASTNode *> children = node->children;
	std::vector<std::vector<bool>> graph_edges(task_names.size(), std::vector<bool>(task_names.size(), 0));
	for (auto child : children)
	{
		if (child->kind == order_rule)
		{
			// fill the graph_edges with the order of the tasks(directed)
			if (!build_order_graph(child, graph_edges, task_mapping))
			{
				return;
			}
		}
	}


	// checking if the graph is cyclic or not
	std::vector<int> visited(task_names.size(), 0);
	std::vector<int> in_degree(task_names.size(), 0);
	for (int i = 0; i < task_names.size(); i++)
	{
		for (int j = 0; j < task_names.size(); j++)
		{
			if (graph_edges[i][j])
				in_degree[j]++;
		}
	}
	std::queue<int> q;
	for (int i = 0; i < task_names.size(); i++)
	{
		if (in_degree[i] == 0)
		{
			q.push(i);
		}
	}
	int count = 0;
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < task_names.size(); i++){
			if (graph_edges[u][i]){
				in_degree[i]--;
				if (in_degree[i] == 0){
					q.push(i);
				}
			}
		}
		count++;
	}

	if (count != task_names.size())
	{
		// detect exact cycle
		std::string message = "";
		// message += "Tasks: ";
		// for (int i = 0; i < task_names.size(); i++)
		// {
		// 	if (!visited[i]){
		// 		message += (task_names[i] + " ");
		// 	}
		// }
		message += "Tasks in "+ node->name + " form parts of cycle";
		yy_sem_error(message);
	}
}

void resolve_shared_block(ASTNode *node, TaskGroup *taskGroupEntry, SymbolTable *global, std::unordered_set<std::string> &identifiers, std::vector<std::string> &task_names, std::unordered_map<std::string, int> &task_mapping){
	std::vector<ASTNode *> children = node->children;

	for(auto child: children){
		if(child->kind == shared_rule){
			ASTNode* left = child->children[0];
			ASTNode* right = child->children[1];
			DataType type = child->type;

			// checking if children of left are all valid task_names/supervisor names
			for(auto grandchild: right->children){
				if(identifiers.find(grandchild->name) == identifiers.end()){
					std::string message = "Task/Supervisor " + grandchild->name + " not declared";
					yy_sem_error(message);
				}
			}



			// checking if names on right are not declared as Function/Struct/TaskGroup
			for(auto grandchild: left->children){
				grandchild->type = type;
				SymbolTableEntry* entry = global->getEntry(grandchild->name);
				if(entry != nullptr && entry->type != variable){ // if the entry is not a variable
					std::string message = "Variable " + grandchild->name + " already declared as a " + entry_type_strings[entry->type];
					yy_sem_error(message);
					continue;
				}

				if(identifiers.find(grandchild->name) != identifiers.end()){
					std::string message = "Variable " + grandchild->name + " already declared as a Task/Supervisor";
					yy_sem_error(message);
					continue;
				}

				for(auto tasks: right->children){
					if(identifiers.find(tasks->name) == identifiers.end())
						continue;

					SymbolTable* task_table = taskGroupEntry->retrieveTask(tasks->name);

					if(task_table->checkName(grandchild->name)){
						std::string message = "Variable " + grandchild->name + " already declared in task " + tasks->name;
						yy_sem_error(message);
					}
					Variable* v = new Variable(grandchild->name, type, grandchild->line_number, grandchild->col_number);
					task_table->addVariable(grandchild->name, v);
				}
			}

		}
	}
}


// //TODO: give types to all the variable_t
// void sem_test(ASTNode* curNode, SymbolTable* current, SymbolTable* global){
//     if(curNode == nullptr)
//         return;
//     switch(curNode->kind){

//         case parallel_stmt:
//         {
//             std::cout << "Checking parallel statement" << std::endl;
//             for(ASTNode* node: curNode->children){
//                 if((node->kind == variable_t))
//                 {
//                     SymbolTableEntry *curEntry = (current->getEntryNested(node->name));
//                     if((curEntry==nullptr)||(curEntry->type == function))
//                     {
//                         std::string message = "Variable " + node->name +" inside "+ node->name+ " list not declared";
//                         yy_sem_error(message);
//                         return;
//                     }
//                     entry_type node_exists = curEntry->type;

//                     // setting the metadata of variables inside the shared, reduction, private
//                     node->type.type = ((Variable *)(curEntry->ptr))->type;
//                     node->type.reference = ((Variable *)(curEntry->ptr))->reference;
//                     node->type.ndims = ((Variable *)(curEntry->ptr))->dims;

//                 }
//             }

//             for(ASTNode* node: curNode->children){
//                 if((node->kind == compound_stmt)||(node->kind == iterative_stmt))
//                     sem_test(node, current, global);
//             }
//             break;
//         }

//         case channel_stmt:
//         {
//             std::cout << "Checking channel statement" << std::endl;
//             for(ASTNode* node: curNode->children){
//                 sem_test(node, current, global);
//             }
//             break;
//         }

//         
//     }

// end:
//     if(curNode->next != nullptr)
//         sem_test(curNode->next, current, global);
// }

// Stores the function names and structs in the global symbol table
void first_pass(ASTNode *node, SymbolTable *global)
{

	if (node == NULL)
		return;

	switch (node->kind)
	{

	case function_decl_stmt:
	{

		// Check if the function is already declared
		if (global->checkName(node->name))
		{
			std::string message = "Function " + node->name + " already declared as a " +
								  entry_type_strings[global->getEntry(node->name)->type];
			yy_sem_error(message);
		}

		std::unordered_set<std::string> param_names;
		std::vector<Variable> params;
		for (auto param_node : node->children[0]->children)
		{
			// Handles Previously declared in list
			if (param_names.find(param_node->name) != param_names.end())
			{

				std::string message = "Variable" + node->name +
									  " previously used in params of the function: " + node->name;
				yy_sem_error(message);
				continue;
			}

			// Handles previously declared variable as some differnt type
			if (global->checkName(param_node->name))
			{

				std::string message = "Variable" + node->name + " previously declared as a " +
									  entry_type_strings[global->getEntry(node->name)->type];
				yy_sem_error(message);
				continue;
			}

			Variable *v = new Variable(param_node->name,
									   param_node->type,
									   param_node->line_number,
									   param_node->col_number);
			params.push_back(*v);
		}

		global->addFunction(
			node->name,
			new Function(node->name, node->type, params, node->line_number, node->col_number));
		break;
	}
	case struct_decl:
	{

		if (global->checkName(node->name))
		{

			std::string message = "Struct " + node->name + " already declared as a " +
								  entry_type_strings[global->getEntry(node->name)->type];
			yy_sem_error(message);
			break;
		}

		std::unordered_set<std::string> param_names;
		std::vector<Variable> params;
		for (int i = 0; (long unsigned int)i < node->children.size(); i++)
		{
			for (auto param_node : node->children[i]->children)
			{
				// Handles Previously declared in list
				if (param_names.find(param_node->name) != param_names.end())
				{

					std::string message =
						"Variable" + node->name + " previously used in Struct: " + node->name;
					// param_node->type = error_type;
					yy_sem_error(message);
					continue;
				}
				SymbolTableEntry *x;
				// Handles previously declared variable as some differnt type
				if (((x = global->getEntry(param_node->name)) != nullptr) && (x->type != variable))
				{

					std::string message = "Variable" + node->name + " previously declared as a " +
										  entry_type_strings[global->getEntry(node->name)->type];
					// param_node->type = error_type;
					yy_sem_error(message);
					continue;
				}

				Variable *v = new Variable(param_node->name,
										   node->children[i]->type,
										   param_node->line_number,
										   param_node->col_number);
				// param_node->type = error_type;
				param_node->type = node->children[i]->type;
				params.push_back(*v);
			}
		}

		global->addStruct(node->name,
						  new Struct(node->name, params, node->line_number, node->col_number));
		break;
	}
	case taskgroup_stmt:
	{
		int order_count = 0, mem_count = 0, shared_count = 0;
		std::vector<ASTNode *> children = node->children;

		std::string taskGroupName = node->name;
		if (global->checkNameNested(taskGroupName))
		{ // Checking if similar named any other thing exists
			std::string message = "Taskgroup " + taskGroupName + " already declared as " + entry_type_strings[global->getEntry(taskGroupName)->type];
			yy_sem_error(message);
			return;
		}

		global->addTaskGroup(taskGroupName);
		TaskGroup *taskGroupEntry = (TaskGroup *)(global->getEntry(taskGroupName)->ptr);
		std::unordered_map<std::string, SymbolTable *> &task_table = taskGroupEntry->task_table;			 // getting reference to the task_table
		std::unordered_map<std::string, SymbolTable *> &supervisor_table = taskGroupEntry->supervisor_table; // getting reference to the supervisor_table
		std::unordered_set<std::string> identifiers;

		for (ASTNode *child : children)
		{
			if (child->kind == properties_stmt)
			{
				order_count += (child->name == "order");
				mem_count += (child->name == "mem");
				shared_count += (child->name == "shared");
				continue;
			}
			if (identifiers.find(child->name) != identifiers.end())
			{ // Checking if the task/supervisor is declared multiple times
				std::string message = "Task/Supervisor " + child->name + " declared multiple times in taskgroup " + taskGroupName;
				yy_sem_error(message);
				return;
			}

			if (global->checkNameNested(child->name))
			{ // Checking if the task/supervisor is declared in the global scope
				std::string message = "Task/Supervisor " + child->name + " already declared as a " + entry_type_strings[global->getEntry(child->name)->type];
				yy_sem_error(message);
				return;
			}
			identifiers.insert(child->name);

			if (child->kind == task_stmt)
				taskGroupEntry->addTask(child->name); // Adding the task to the task_table
			else if (child->kind == supervisor_stmt)
				taskGroupEntry->addSupervisor(child->name); // Adding the supervisor to the supervisor_table
		}

		// names of any taskgroup/supervisor is not allowed
		for (auto name : identifiers)
		{
			forbidden_names.insert(name);
		}

		if (order_count > 1 || mem_count > 1 || shared_count > 1)
		{ // Checking if the properties are declared multiple times
			std::string message = "Property declared multiple times in taskgroup " + taskGroupName;
			yy_sem_error(message);
			return;
		}
		std::reverse(children.begin(), children.end());
	}
	case syntax_error_stmt:
	{

		break;
	}
	default:
		break;
	}

	// Recursively call the function for the next node
	if (node->next != NULL)
		first_pass(node->next, global);
}

void handle_statement(ASTNode *node, SymbolTable *current, SymbolTable *global)
{
	switch (node->kind)
	{

	case expr_stmt:
	case literal:
	case variable_t:
	case function_call_stmt:
	case identifier_chain:
	case array_element:
	{
		resolve_expression(node, current, global);
		break;
	}

	case taskgroup_stmt:
	{

		if (!global->checkName(node->name, taskgroup))
		{
			std::string message = node->name + "not declared as a TaskGroup";
			yy_sem_error(message);
			return;
		}

		TaskGroup *taskGroupEntry = (TaskGroup*)(global->getEntry(node->name)->ptr);
		std::unordered_set<std::string> identifiers;
		// getting all the valus required for checking taskgroup properties
		for (const auto &entry : taskGroupEntry->task_table)
			identifiers.insert(entry.first);

		for (const auto &entry : taskGroupEntry->supervisor_table)
			identifiers.insert(entry.first);

		std::vector<std::string> task_names;
		for (auto kv : taskGroupEntry->task_table)
		{
			task_names.push_back(kv.first);
		}

		std::unordered_map<std::string, int> task_mapping; // writing a task_mapping
		for (int i = 0; i < task_names.size(); i++)
			task_mapping[task_names[i]] = i;

		for (auto child : node->children)
		{
			if (child->kind == properties_stmt)
			{
				if (child->name == "order")
					resolve_order_block(child, taskGroupEntry, global, identifiers, task_names, task_mapping);
				else if(child->name == "shared")
					resolve_shared_block(child, taskGroupEntry, global, identifiers, task_names, task_mapping);
				
			}
		}

		for(auto child: node->children){
			if(child->kind == task_stmt || child->kind == supervisor_stmt){
				if(identifiers.find(child->name) == identifiers.end()){
					continue;
				}
				SymbolTable* new_table = nullptr;
				if(child->kind == task_stmt){
					new_table = taskGroupEntry->retrieveTask(child->name);
				}
				else if(child->kind == supervisor_stmt){
					new_table = taskGroupEntry->retrieveSupervisor(child->name);
				}

				if(child->childExists()){
					ASTNode* compound = child->children[0];
					new_table->next = current;
					while(compound != nullptr){
						handle_statement(compound, new_table, global);
						compound = compound->next;
					}
					new_table->next = nullptr;
				}

				delete new_table;	
			}
		}

		break;
	}

	case decl_stmt:
	{
		DataType type = node->type;

		if (node->type.type == struct_t)
		{
			if (global->getEntry(node->type.name) == nullptr)
			{
				std::string message = "Struct " + node->type.name + " not declared";
				yy_sem_error(message, node->line_number, node->col_number);
				break;
			}
		}
		for (auto child : node->children)
		{ // all declarations of this type
			if (current->checkName(child->name))
			{
				std::string message = "Variable " + child->name + " already declared";
				yy_sem_error(message, child->line_number, child->col_number);
				continue;
			}

			if (forbidden_names.find(child->name) != forbidden_names.end())
			{
				std::string message = "Variable " + child->name + " has been reserved by a Task/Supervisor";
				yy_sem_error(message, child->line_number, child->col_number);
				continue;
			}
			if (global->getEntry(child->name) != nullptr &&
				global->getEntry(child->name)->type != variable)
			{ // if the entry is not a variable
				std::string message = "Variable " + child->name + " already declared as a " +
									  entry_type_strings[global->getEntry(child->name)->type];
				yy_sem_error(message, child->line_number, child->col_number);
				continue;
			}

			Variable *v = new Variable(child->name, type, child->line_number, child->col_number);
			current->addVariable(child->name, v);
			child->type = type;
			if (child->childExists())
			{
				// handle
				if (child->children[0]->kind != list_init)
				{
					resolve_expression(child->children[0], current, global);

					if (resolve_binary_operator(child, child->children[0], "=", current, global) ==
						error_type)
					{
						std::string message =
							"Type mismatch in variable Declaration " + child->name;
						yy_sem_error(message, child->children[0]->line_number,
										child->children[0]->col_number);
					}
				}
				else
				{
					if (!match_list_init(child->children[0], type, global, current))
					{
						std::string message =
							"Type mismatch in variable Declaration in list initializer of " +
							child->name;
						yy_sem_error(message, child->children[0]->line_number,
										child->children[0]->col_number);
					}
				}
			}
		}
		break;
	}
	case selection_stmt:
	{
		for (auto child : node->children)
		{
			ASTNode *compound = child->children[0];
			if (child->kind == if_stmt)
			{
				resolve_expression(child->children[0], current, global);
				if (child->children[0]->type.type != bool_t &&
					child->children[0]->type.type != int_t &&
					child->children[0]->type.type != float_type &&
					child->children[0]->type.type != long_t)
				{
					std::string message =
						"Conditional statement can't be resolved into boolean expression";
					yy_sem_error(message);
				}

				compound = child->children[1];
			}
			if (compound->childExists())
			{
				SymbolTable *new_table = new SymbolTable();
				new_table->next = current;
				second_pass(compound->children[0], new_table, global);
				new_table->next = nullptr;
				delete new_table;
			}
		}
		break;
	}
	case jump_stmt:
	{
		if (node->name == "break" || node->name == "continue")
		{
			if (num_loops == 0)
			{
				std::string message = "Can't use Control sequences outside of a loop";
				yy_sem_error(message);
			}
		}
		break;
	}
	case iterative_stmt:
	{
		SymbolTable *new_table = new SymbolTable();
		new_table->next = current;
		num_loops++;
		ASTNode *first_child = node->children[0];
		if (first_child->name == "type1")
		{
			for (auto child_node : first_child->children)
			{
				if (child_node != nullptr)
					resolve_expression(child_node, new_table, global);
			}
		}
		else
		{ // this one declares variable in new scope
			ASTNode *container = first_child->children[1];
			resolve_expression(container, current, global);
			if (container->type == error_type)
			{
				std::string message = "Iteration not possible on Error Type";
				yy_sem_error(message);
				goto inside_of_the_loop;
			}

			if (container->type.ndims.size() == 0)
			{
				std::string message = "The expression doesn't result in an array";
				yy_sem_error(message);
				goto inside_of_the_loop;
			}
		inside_of_the_loop:
			// declare new data type in new table
			DataType new_type = container->type;
			if (new_type.ndims.size() != 0)
				new_type.ndims.pop_back();
			first_child->children[0]->type = new_type;
			new_type.reference = first_child->children[0]->type.reference;
			new_table->addVariable(first_child->children[0]->name,
								   new Variable(first_child->children[0]->name,
												new_type,
												first_child->children[0]->line_number,
												first_child->children[0]->col_number));
		}

		if (node->children[1]->childExists())
		{
			second_pass(node->children[1]->children[0], new_table, global);
		}
		new_table->next = nullptr;
		num_loops--;
		delete new_table;
		break;
	}
	case compound_stmt:
	{
		SymbolTable *new_table = new SymbolTable();
		new_table->next = current;
		if (node->childExists())
		{
			second_pass(node->children[0], new_table, global);
		}
		new_table->next = nullptr;
		delete new_table;
		break;
	}
	case function_decl_stmt:
	{
		std::string name = node->name;
		if (!global->checkName(name, function))
		{
			break;
		}
		Function *func = (Function *)global->getEntry(name)->ptr;

		SymbolTable *new_table = new SymbolTable();

		new_table->next = current;

		for (Variable var : func->param_list)
			new_table->addVariable(var.name, &var);

		DataType return_type = func->return_type;
		ASTNode *stmts = node->children[1];

		bool last = false;
		if (stmts->childExists())
		{
			ASTNode *child = stmts->children[0];
			while (child != nullptr)
			{
				if (child->kind != return_stmt)
					handle_statement(child, new_table, global);
				// special handling for matching datatype
				else
				{
					if (child->childExists())
					{
						resolve_expression(child->children[0], new_table, global);
						if (child->children[0]->type != return_type)
						{
							std::string message = "Return type mismatch in function " + name;
							yy_sem_error(message);
						}
						last = true;
					}
					else
					{
						if (return_type.type != void_t)
						{
							std::string message = "Return type mismatch in function " + name;
							yy_sem_error(message);
						}
					}
				}
				child = child->next;
			}
		}

		if (!last && return_type.type != void_t)
		{
			std::string message = "Function reaches end without returning a value";
			yy_sem_error(message);
		}
		new_table->next = nullptr;
		delete new_table;
		break;
	}
	case channel_stmt:
	{
		for (ASTNode *thisNode : node->children)
		{
			second_pass(thisNode, current, global);
		}

		break;
	}
	case parallel_stmt:
	{
		for (ASTNode *thisNode : node->children)
		{
			if ((thisNode->kind == variable_t))
			{
				SymbolTableEntry *curEntry = (current->getEntryNested(thisNode->name));
				if ((curEntry == nullptr) || (curEntry->type == function))
				{
					std::string message = "Variable " + thisNode->name + " inside " + thisNode->name + " list not declared";
					yy_sem_error(message);
					return;
				}
				entry_type node_exists = curEntry->type;

				// setting the metadata of variables inside the shared, reduction, private
				thisNode->type = ((Variable *)(curEntry->ptr))->type.type;
				// thisNode->type = ((Variable *)(curEntry->ptr))->type.reference;

				thisNode->type = DataType(((Variable *)(curEntry->ptr))->type.type, ((Variable *)(curEntry->ptr))->type.ndims, ((Variable *)(curEntry->ptr))->type.reference);
			}
		}

		for (ASTNode *thisNode : node->children)
		{
			if ((thisNode->kind == compound_stmt) || (thisNode->kind == iterative_stmt))
				second_pass(thisNode, current, global);
		}
		break;
	}
	case keyword:
	{
		std::cout << "Reached keyword" << std::endl;
		break;
	}
	default:
	{
		break;
	}
	}
}
void second_pass(ASTNode *node, SymbolTable *current, SymbolTable *global)
{

	if (node == nullptr)
		return;

	handle_statement(node, current, global);
	// Recursively call the function for the next node
	if (node->next != NULL)
		second_pass(node->next, current, global);
}