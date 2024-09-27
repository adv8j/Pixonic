/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
int yylex(void);
extern void yyerror(char *s);

#line 77 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ASSIGN = 258,                  /* ASSIGN  */
    PLUS = 259,                    /* PLUS  */
    MINUS = 260,                   /* MINUS  */
    MUL = 261,                     /* MUL  */
    DIV = 262,                     /* DIV  */
    MOD = 263,                     /* MOD  */
    EQ = 264,                      /* EQ  */
    NEQ = 265,                     /* NEQ  */
    GT = 266,                      /* GT  */
    LT = 267,                      /* LT  */
    GTE = 268,                     /* GTE  */
    LTE = 269,                     /* LTE  */
    AND = 270,                     /* AND  */
    OR = 271,                      /* OR  */
    NOT = 272,                     /* NOT  */
    ADD_ASSIGN = 273,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 274,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 275,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 276,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 277,              /* MOD_ASSIGN  */
    SEMICOLON = 278,               /* SEMICOLON  */
    COLON = 279,                   /* COLON  */
    LPAREN = 280,                  /* LPAREN  */
    RPAREN = 281,                  /* RPAREN  */
    LBRACKET = 282,                /* LBRACKET  */
    RBRACKET = 283,                /* RBRACKET  */
    LBRACE = 284,                  /* LBRACE  */
    RBRACE = 285,                  /* RBRACE  */
    COMMA = 286,                   /* COMMA  */
    DOT = 287,                     /* DOT  */
    RANGE = 288,                   /* RANGE  */
    RANGE_INCL = 289,              /* RANGE_INCL  */
    REFERENCE = 290,               /* REFERENCE  */
    TASKGROUP = 291,               /* TASKGROUP  */
    TASK = 292,                    /* TASK  */
    PROPERTIES = 293,              /* PROPERTIES  */
    ORDER = 294,                   /* ORDER  */
    MEM = 295,                     /* MEM  */
    SHARED_DIRECTIVE = 296,        /* SHARED_DIRECTIVE  */
    SUPERVISOR = 297,              /* SUPERVISOR  */
    ALL = 298,                     /* ALL  */
    UNSAFE = 299,                  /* UNSAFE  */
    JOIN = 300,                    /* JOIN  */
    CALL = 301,                    /* CALL  */
    CHN_SEND = 302,                /* CHN_SEND  */
    CHANNEL_WAIT = 303,            /* CHANNEL_WAIT  */
    TASK_CHANNEL = 304,            /* TASK_CHANNEL  */
    LOG = 305,                     /* LOG  */
    ARROW = 306,                   /* ARROW  */
    PARALLEL = 307,                /* PARALLEL  */
    PRIVATE = 308,                 /* PRIVATE  */
    SHARED = 309,                  /* SHARED  */
    SCHEDULE = 310,                /* SCHEDULE  */
    NUM_THREADS = 311,             /* NUM_THREADS  */
    REDUCTION = 312,               /* REDUCTION  */
    DYNAMIC_SCHEDULE = 313,        /* DYNAMIC_SCHEDULE  */
    STATIC_SCHEDULE = 314,         /* STATIC_SCHEDULE  */
    MUT = 315,                     /* MUT  */
    INT = 316,                     /* INT  */
    CHAR = 317,                    /* CHAR  */
    LONG = 318,                    /* LONG  */
    BOOL = 319,                    /* BOOL  */
    FLOAT = 320,                   /* FLOAT  */
    STRING = 321,                  /* STRING  */
    FUNC = 322,                    /* FUNC  */
    RETURN = 323,                  /* RETURN  */
    CONTINUE = 324,                /* CONTINUE  */
    BREAK = 325,                   /* BREAK  */
    STRUCT = 326,                  /* STRUCT  */
    IF = 327,                      /* IF  */
    ELSE = 328,                    /* ELSE  */
    FOR = 329,                     /* FOR  */
    IN = 330,                      /* IN  */
    TRUE = 331,                    /* TRUE  */
    FALSE = 332,                   /* FALSE  */
    IDENTIFIER = 333,              /* IDENTIFIER  */
    SHARED_IDENTIFIER = 334,       /* SHARED_IDENTIFIER  */
    INT_LITERAL = 335,             /* INT_LITERAL  */
    FLOAT_LITERAL = 336,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 337,          /* STRING_LITERAL  */
    CHARACTER_LITERAL = 338        /* CHARACTER_LITERAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ASSIGN 258
#define PLUS 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define MOD 263
#define EQ 264
#define NEQ 265
#define GT 266
#define LT 267
#define GTE 268
#define LTE 269
#define AND 270
#define OR 271
#define NOT 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define MOD_ASSIGN 277
#define SEMICOLON 278
#define COLON 279
#define LPAREN 280
#define RPAREN 281
#define LBRACKET 282
#define RBRACKET 283
#define LBRACE 284
#define RBRACE 285
#define COMMA 286
#define DOT 287
#define RANGE 288
#define RANGE_INCL 289
#define REFERENCE 290
#define TASKGROUP 291
#define TASK 292
#define PROPERTIES 293
#define ORDER 294
#define MEM 295
#define SHARED_DIRECTIVE 296
#define SUPERVISOR 297
#define ALL 298
#define UNSAFE 299
#define JOIN 300
#define CALL 301
#define CHN_SEND 302
#define CHANNEL_WAIT 303
#define TASK_CHANNEL 304
#define LOG 305
#define ARROW 306
#define PARALLEL 307
#define PRIVATE 308
#define SHARED 309
#define SCHEDULE 310
#define NUM_THREADS 311
#define REDUCTION 312
#define DYNAMIC_SCHEDULE 313
#define STATIC_SCHEDULE 314
#define MUT 315
#define INT 316
#define CHAR 317
#define LONG 318
#define BOOL 319
#define FLOAT 320
#define STRING 321
#define FUNC 322
#define RETURN 323
#define CONTINUE 324
#define BREAK 325
#define STRUCT 326
#define IF 327
#define ELSE 328
#define FOR 329
#define IN 330
#define TRUE 331
#define FALSE 332
#define IDENTIFIER 333
#define SHARED_IDENTIFIER 334
#define INT_LITERAL 335
#define FLOAT_LITERAL 336
#define STRING_LITERAL 337
#define CHARACTER_LITERAL 338

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN = 3,                     /* ASSIGN  */
  YYSYMBOL_PLUS = 4,                       /* PLUS  */
  YYSYMBOL_MINUS = 5,                      /* MINUS  */
  YYSYMBOL_MUL = 6,                        /* MUL  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_MOD = 8,                        /* MOD  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_NEQ = 10,                       /* NEQ  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_LT = 12,                        /* LT  */
  YYSYMBOL_GTE = 13,                       /* GTE  */
  YYSYMBOL_LTE = 14,                       /* LTE  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_ADD_ASSIGN = 18,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 19,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 20,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 21,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 22,                /* MOD_ASSIGN  */
  YYSYMBOL_SEMICOLON = 23,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 24,                     /* COLON  */
  YYSYMBOL_LPAREN = 25,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 26,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 27,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 28,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 29,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 30,                    /* RBRACE  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_RANGE = 33,                     /* RANGE  */
  YYSYMBOL_RANGE_INCL = 34,                /* RANGE_INCL  */
  YYSYMBOL_REFERENCE = 35,                 /* REFERENCE  */
  YYSYMBOL_TASKGROUP = 36,                 /* TASKGROUP  */
  YYSYMBOL_TASK = 37,                      /* TASK  */
  YYSYMBOL_PROPERTIES = 38,                /* PROPERTIES  */
  YYSYMBOL_ORDER = 39,                     /* ORDER  */
  YYSYMBOL_MEM = 40,                       /* MEM  */
  YYSYMBOL_SHARED_DIRECTIVE = 41,          /* SHARED_DIRECTIVE  */
  YYSYMBOL_SUPERVISOR = 42,                /* SUPERVISOR  */
  YYSYMBOL_ALL = 43,                       /* ALL  */
  YYSYMBOL_UNSAFE = 44,                    /* UNSAFE  */
  YYSYMBOL_JOIN = 45,                      /* JOIN  */
  YYSYMBOL_CALL = 46,                      /* CALL  */
  YYSYMBOL_CHN_SEND = 47,                  /* CHN_SEND  */
  YYSYMBOL_CHANNEL_WAIT = 48,              /* CHANNEL_WAIT  */
  YYSYMBOL_TASK_CHANNEL = 49,              /* TASK_CHANNEL  */
  YYSYMBOL_LOG = 50,                       /* LOG  */
  YYSYMBOL_ARROW = 51,                     /* ARROW  */
  YYSYMBOL_PARALLEL = 52,                  /* PARALLEL  */
  YYSYMBOL_PRIVATE = 53,                   /* PRIVATE  */
  YYSYMBOL_SHARED = 54,                    /* SHARED  */
  YYSYMBOL_SCHEDULE = 55,                  /* SCHEDULE  */
  YYSYMBOL_NUM_THREADS = 56,               /* NUM_THREADS  */
  YYSYMBOL_REDUCTION = 57,                 /* REDUCTION  */
  YYSYMBOL_DYNAMIC_SCHEDULE = 58,          /* DYNAMIC_SCHEDULE  */
  YYSYMBOL_STATIC_SCHEDULE = 59,           /* STATIC_SCHEDULE  */
  YYSYMBOL_MUT = 60,                       /* MUT  */
  YYSYMBOL_INT = 61,                       /* INT  */
  YYSYMBOL_CHAR = 62,                      /* CHAR  */
  YYSYMBOL_LONG = 63,                      /* LONG  */
  YYSYMBOL_BOOL = 64,                      /* BOOL  */
  YYSYMBOL_FLOAT = 65,                     /* FLOAT  */
  YYSYMBOL_STRING = 66,                    /* STRING  */
  YYSYMBOL_FUNC = 67,                      /* FUNC  */
  YYSYMBOL_RETURN = 68,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 69,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 70,                     /* BREAK  */
  YYSYMBOL_STRUCT = 71,                    /* STRUCT  */
  YYSYMBOL_IF = 72,                        /* IF  */
  YYSYMBOL_ELSE = 73,                      /* ELSE  */
  YYSYMBOL_FOR = 74,                       /* FOR  */
  YYSYMBOL_IN = 75,                        /* IN  */
  YYSYMBOL_TRUE = 76,                      /* TRUE  */
  YYSYMBOL_FALSE = 77,                     /* FALSE  */
  YYSYMBOL_IDENTIFIER = 78,                /* IDENTIFIER  */
  YYSYMBOL_SHARED_IDENTIFIER = 79,         /* SHARED_IDENTIFIER  */
  YYSYMBOL_INT_LITERAL = 80,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 81,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 82,            /* STRING_LITERAL  */
  YYSYMBOL_CHARACTER_LITERAL = 83,         /* CHARACTER_LITERAL  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_program = 85,                   /* program  */
  YYSYMBOL_statement_list = 86,            /* statement_list  */
  YYSYMBOL_one_or_more_statements = 87,    /* one_or_more_statements  */
  YYSYMBOL_generic_dtypes = 88,            /* generic_dtypes  */
  YYSYMBOL_dtype = 89,                     /* dtype  */
  YYSYMBOL_array = 90,                     /* array  */
  YYSYMBOL_array_element = 91,             /* array_element  */
  YYSYMBOL_dims = 92,                      /* dims  */
  YYSYMBOL_initializer_dims = 93,          /* initializer_dims  */
  YYSYMBOL_statement = 94,                 /* statement  */
  YYSYMBOL_inner_statement = 95,           /* inner_statement  */
  YYSYMBOL_one_or_more_inner_statements = 96, /* one_or_more_inner_statements  */
  YYSYMBOL_inner_statement_list = 97,      /* inner_statement_list  */
  YYSYMBOL_return_statement = 98,          /* return_statement  */
  YYSYMBOL_compound_statement = 99,        /* compound_statement  */
  YYSYMBOL_expression_statement = 100,     /* expression_statement  */
  YYSYMBOL_expression = 101,               /* expression  */
  YYSYMBOL_function_call = 102,            /* function_call  */
  YYSYMBOL_fn_call_argument_list = 103,    /* fn_call_argument_list  */
  YYSYMBOL_unary_operator = 104,           /* unary_operator  */
  YYSYMBOL_arithmetic_expression = 105,    /* arithmetic_expression  */
  YYSYMBOL_assignment_expression = 106,    /* assignment_expression  */
  YYSYMBOL_unary_expression = 107,         /* unary_expression  */
  YYSYMBOL_comparison_expression = 108,    /* comparison_expression  */
  YYSYMBOL_logical_expression = 109,       /* logical_expression  */
  YYSYMBOL_declaration_statement = 110,    /* declaration_statement  */
  YYSYMBOL_declaration_list = 111,         /* declaration_list  */
  YYSYMBOL_declaration = 112,              /* declaration  */
  YYSYMBOL_value_assign = 113,             /* value_assign  */
  YYSYMBOL_iterative_statement = 114,      /* iterative_statement  */
  YYSYMBOL_container = 115,                /* container  */
  YYSYMBOL_iterator = 116,                 /* iterator  */
  YYSYMBOL_range = 117,                    /* range  */
  YYSYMBOL_number = 118,                   /* number  */
  YYSYMBOL_selection_statement = 119,      /* selection_statement  */
  YYSYMBOL_if_chain_statement = 120,       /* if_chain_statement  */
  YYSYMBOL_function_declaration = 121,     /* function_declaration  */
  YYSYMBOL_datatype_and_ref = 122,         /* datatype_and_ref  */
  YYSYMBOL_argument_dtype = 123,           /* argument_dtype  */
  YYSYMBOL_argument_list = 124,            /* argument_list  */
  YYSYMBOL_argument_declaration = 125,     /* argument_declaration  */
  YYSYMBOL_parallel_statement = 126,       /* parallel_statement  */
  YYSYMBOL_parallel_stmt_argument_list = 127, /* parallel_stmt_argument_list  */
  YYSYMBOL_parallel_stmt_argument = 128,   /* parallel_stmt_argument  */
  YYSYMBOL_schedule_list = 129,            /* schedule_list  */
  YYSYMBOL_reduction_list = 130,           /* reduction_list  */
  YYSYMBOL_reduction_operator_list = 131,  /* reduction_operator_list  */
  YYSYMBOL_channel_statement = 132,        /* channel_statement  */
  YYSYMBOL_signal_statement = 133,         /* signal_statement  */
  YYSYMBOL_task_all = 134,                 /* task_all  */
  YYSYMBOL_wait_statement = 135,           /* wait_statement  */
  YYSYMBOL_taskgroup_statement = 136,      /* taskgroup_statement  */
  YYSYMBOL_taskgroup_argument_list = 137,  /* taskgroup_argument_list  */
  YYSYMBOL_taskgroup_argument = 138,       /* taskgroup_argument  */
  YYSYMBOL_taskgroup_definition = 139,     /* taskgroup_definition  */
  YYSYMBOL_task_declaration_list = 140,    /* task_declaration_list  */
  YYSYMBOL_task_declaration = 141,         /* task_declaration  */
  YYSYMBOL_supervisor_statement_list = 142, /* supervisor_statement_list  */
  YYSYMBOL_supervisor_statements = 143,    /* supervisor_statements  */
  YYSYMBOL_task_statement_list = 144,      /* task_statement_list  */
  YYSYMBOL_task_statements = 145,          /* task_statements  */
  YYSYMBOL_properties_declaration = 146,   /* properties_declaration  */
  YYSYMBOL_taskgroup_properties = 147,     /* taskgroup_properties  */
  YYSYMBOL_taskgroup_property = 148,       /* taskgroup_property  */
  YYSYMBOL_order_block = 149,              /* order_block  */
  YYSYMBOL_order_rule_list = 150,          /* order_rule_list  */
  YYSYMBOL_order_rule = 151,               /* order_rule  */
  YYSYMBOL_order_rule_start = 152,         /* order_rule_start  */
  YYSYMBOL_order_rule_mid = 153,           /* order_rule_mid  */
  YYSYMBOL_order_rule_end = 154,           /* order_rule_end  */
  YYSYMBOL_identifier_list = 155,          /* identifier_list  */
  YYSYMBOL_shared_block = 156,             /* shared_block  */
  YYSYMBOL_shared_rule_list = 157,         /* shared_rule_list  */
  YYSYMBOL_shared_rule = 158,              /* shared_rule  */
  YYSYMBOL_mem_block = 159,                /* mem_block  */
  YYSYMBOL_mem_statement_list = 160,       /* mem_statement_list  */
  YYSYMBOL_mem_statement = 161,            /* mem_statement  */
  YYSYMBOL_mem_taskgroup_list = 162,       /* mem_taskgroup_list  */
  YYSYMBOL_mem_taskgroup_name = 163,       /* mem_taskgroup_name  */
  YYSYMBOL_other_statements = 164,         /* other_statements  */
  YYSYMBOL_join_statement = 165,           /* join_statement  */
  YYSYMBOL_call_statement = 166,           /* call_statement  */
  YYSYMBOL_array_literal = 167,            /* array_literal  */
  YYSYMBOL_literals = 168,                 /* literals  */
  YYSYMBOL_value = 169,                    /* value  */
  YYSYMBOL_identifier_chain = 170          /* identifier_chain  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  220
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  394

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   338


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    46,    47,    48,    49,    54,    55,    56,
      57,    58,    59,    60,    64,    65,    69,    73,    78,    79,
      83,    84,    90,    91,    92,    93,    94,    95,    96,    97,
     100,   101,   103,   104,   106,   107,   108,   109,   110,   111,
     112,   116,   117,   118,   121,   128,   129,   136,   137,   138,
     139,   140,   141,   142,   143,   147,   148,   150,   151,   152,
     158,   159,   164,   165,   166,   167,   168,   172,   173,   174,
     175,   176,   177,   183,   188,   189,   190,   191,   192,   193,
     197,   198,   203,   206,   207,   211,   212,   215,   216,   221,
     222,   228,   229,   232,   233,   237,   238,   242,   243,   248,
     249,   253,   254,   259,   264,   264,   267,   268,   271,   272,
     273,   276,   277,   282,   283,   284,   286,   287,   290,   291,
     292,   293,   294,   297,   297,   301,   302,   306,   307,   308,
     309,   310,   313,   314,   318,   319,   322,   323,   327,   328,
     331,   332,   335,   336,   338,   339,   341,   342,   346,   347,
     350,   351,   352,   357,   358,   361,   362,   363,   364,   365,
     366,   367,   368,   372,   373,   377,   378,   379,   380,   381,
     382,   383,   387,   388,   393,   394,   398,   399,   400,   404,
     409,   410,   414,   419,   420,   424,   425,   429,   430,   434,
     435,   439,   444,   445,   449,   455,   456,   462,   463,   468,
     473,   474,   479,   480,   485,   486,   489,   494,   499,   503,
     503,   503,   503,   503,   503,   503,   506,   507,   508,   512,
     513
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "EQ", "NEQ", "GT", "LT", "GTE", "LTE",
  "AND", "OR", "NOT", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "SEMICOLON", "COLON", "LPAREN", "RPAREN",
  "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "COMMA", "DOT", "RANGE",
  "RANGE_INCL", "REFERENCE", "TASKGROUP", "TASK", "PROPERTIES", "ORDER",
  "MEM", "SHARED_DIRECTIVE", "SUPERVISOR", "ALL", "UNSAFE", "JOIN", "CALL",
  "CHN_SEND", "CHANNEL_WAIT", "TASK_CHANNEL", "LOG", "ARROW", "PARALLEL",
  "PRIVATE", "SHARED", "SCHEDULE", "NUM_THREADS", "REDUCTION",
  "DYNAMIC_SCHEDULE", "STATIC_SCHEDULE", "MUT", "INT", "CHAR", "LONG",
  "BOOL", "FLOAT", "STRING", "FUNC", "RETURN", "CONTINUE", "BREAK",
  "STRUCT", "IF", "ELSE", "FOR", "IN", "TRUE", "FALSE", "IDENTIFIER",
  "SHARED_IDENTIFIER", "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL",
  "CHARACTER_LITERAL", "$accept", "program", "statement_list",
  "one_or_more_statements", "generic_dtypes", "dtype", "array",
  "array_element", "dims", "initializer_dims", "statement",
  "inner_statement", "one_or_more_inner_statements",
  "inner_statement_list", "return_statement", "compound_statement",
  "expression_statement", "expression", "function_call",
  "fn_call_argument_list", "unary_operator", "arithmetic_expression",
  "assignment_expression", "unary_expression", "comparison_expression",
  "logical_expression", "declaration_statement", "declaration_list",
  "declaration", "value_assign", "iterative_statement", "container",
  "iterator", "range", "number", "selection_statement",
  "if_chain_statement", "function_declaration", "datatype_and_ref",
  "argument_dtype", "argument_list", "argument_declaration",
  "parallel_statement", "parallel_stmt_argument_list",
  "parallel_stmt_argument", "schedule_list", "reduction_list",
  "reduction_operator_list", "channel_statement", "signal_statement",
  "task_all", "wait_statement", "taskgroup_statement",
  "taskgroup_argument_list", "taskgroup_argument", "taskgroup_definition",
  "task_declaration_list", "task_declaration", "supervisor_statement_list",
  "supervisor_statements", "task_statement_list", "task_statements",
  "properties_declaration", "taskgroup_properties", "taskgroup_property",
  "order_block", "order_rule_list", "order_rule", "order_rule_start",
  "order_rule_mid", "order_rule_end", "identifier_list", "shared_block",
  "shared_rule_list", "shared_rule", "mem_block", "mem_statement_list",
  "mem_statement", "mem_taskgroup_list", "mem_taskgroup_name",
  "other_statements", "join_statement", "call_statement", "array_literal",
  "literals", "value", "identifier_chain", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-195)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-108)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     441,  -195,  -195,  -195,   162,   147,   -52,    19,  -195,  -195,
    -195,  -195,  -195,  -195,    39,    51,    48,   -18,  -195,  -195,
     135,   157,  -195,  -195,  -195,   159,  -195,   441,    70,   -22,
    -195,  -195,  -195,  -195,  -195,   476,  -195,   -47,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,   213,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,   133,   550,   162,   151,   172,   150,   147,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,   146,   178,
    -195,   361,  -195,   162,    13,   107,  -195,   126,    44,   -47,
     180,  -195,  -195,   187,   142,   219,     1,  -195,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,  -195,  -195,  -195,
    -195,  -195,  -195,   -47,   163,  -195,   622,  -195,  -195,  -195,
    -195,    36,   -14,   223,   234,   245,   247,   249,    32,  -195,
     229,   574,    13,  -195,   120,  -195,   643,    97,   227,   -47,
     -47,  -195,   253,   162,  -195,  -195,   -22,   643,   197,   197,
    -195,  -195,  -195,   295,   295,   316,   316,   316,   316,   269,
     127,   643,   643,   643,   643,   643,  -195,  -195,  -195,   261,
     268,   260,   256,   210,   215,   264,   106,  -195,   271,   277,
      92,   211,   283,   -23,   178,   361,   266,   162,   282,   266,
    -195,  -195,   162,  -195,   286,    53,   239,   643,  -195,   236,
     -47,   296,    36,   148,   297,   304,   306,  -195,  -195,   258,
     258,  -195,  -195,  -195,  -195,   378,  -195,  -195,  -195,    -7,
     302,   262,  -195,   123,  -195,   278,   598,  -195,   643,  -195,
     -47,  -195,  -195,  -195,   -14,  -195,   299,  -195,  -195,  -195,
    -195,  -195,   158,   165,   318,   332,   333,   338,   340,   138,
    -195,     2,  -195,   363,   266,   361,    -4,  -195,   266,   339,
     341,   366,   329,   267,   117,  -195,   298,  -195,   258,   258,
     258,   258,   258,   378,  -195,   162,  -195,  -195,  -195,  -195,
    -195,  -195,   350,   -47,  -195,   345,   354,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,   352,   357,  -195,  -195,   309,   310,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,   360,     8,   368,  -195,  -195,  -195,  -195,  -195,
     367,   367,   367,   367,   367,  -195,   643,  -195,   373,   324,
     370,   371,  -195,  -195,   381,   392,  -195,  -195,   388,  -195,
     390,   397,   403,   162,  -195,  -195,    -3,   -11,  -195,     4,
    -195,   162,  -195,   643,  -195,   379,  -195,   258,  -195,   -10,
    -195,     9,  -195,    11,  -195,   391,   522,  -195,    -1,   367,
     353,  -195,   361,  -195,   382,  -195,   -32,  -195,   374,    22,
    -195,   384,   358,   414,   367,  -195,  -195,   353,   258,  -195,
    -195,  -195,    24,  -195
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    60,    61,    46,     0,    31,     0,     0,     7,    12,
       8,    11,     9,    10,     0,     0,     0,     0,   213,   214,
     220,   209,   210,   211,   212,     0,     2,     3,    14,     0,
      15,   218,     6,    25,    24,     0,    54,     0,    50,    49,
      53,    52,    51,    28,    22,     0,    23,    26,    29,    27,
     215,   216,    47,   217,     0,     0,     0,     0,     0,    30,
      33,    40,    37,    36,    38,    34,    35,    39,     0,     0,
     114,     0,    13,     0,     0,     0,    93,     0,    59,     0,
      17,     1,     5,    21,     0,    88,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,    98,    97,
      73,    95,    96,     0,     0,    48,     0,    43,    42,    44,
      32,     0,   147,     0,     0,     0,     0,     0,     0,   117,
       0,     0,     0,    94,     0,    55,    58,     0,     0,     0,
       0,    16,     0,     0,    86,    82,     0,    67,    62,    63,
      64,    65,    66,    78,    79,    75,    74,    76,    77,    80,
      81,    68,    69,    70,    71,    72,   208,   219,    41,     0,
       0,     0,   143,     0,     0,     0,   173,   149,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,    98,     0,
      92,    56,     0,    19,     0,     0,     0,    87,    83,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   146,     0,
       0,   124,   123,   121,   122,     0,   113,   115,   116,    14,
       0,     0,   104,     0,   109,   102,     0,    90,    57,    18,
       0,    85,   144,   145,   147,   142,     0,   164,   154,   141,
     175,   190,     0,     0,     0,     0,     0,     0,     0,     0,
     126,    21,   105,   111,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,   119,     0,   118,     0,     0,
       0,     0,     0,     0,   120,     0,   103,   108,   100,   101,
      89,    20,     0,     0,   150,     0,   137,   168,   167,   169,
     165,   166,   170,   171,     0,     0,   163,   152,     0,     0,
     158,   157,   159,   155,   156,   160,   161,   153,   162,   204,
     205,   172,     0,     0,     0,   174,   176,   177,   178,   189,
     127,   128,   129,   130,   131,   125,   112,   140,     0,     0,
       0,   135,   132,   133,     0,     0,   181,   198,     0,   193,
       0,     0,     0,     0,   206,   207,   184,     0,   198,     0,
     164,     0,   136,   134,   179,     0,   180,     0,   195,     0,
     197,     0,   191,     0,   192,     0,     0,   183,     0,   186,
       0,   196,     0,   151,   138,   188,     0,   182,   202,     0,
     201,     0,     0,     0,   185,   203,   199,     0,     0,   139,
     187,   200,     0,   194
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -195,  -195,  -195,  -195,  -176,   -67,  -195,  -195,   -27,  -195,
     411,  -195,  -195,   383,  -195,    -5,    -2,    10,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,     5,  -195,   301,  -195,
       0,  -195,  -195,  -195,     6,     3,  -195,  -195,  -195,  -195,
    -195,   186,     7,  -195,   265,  -195,  -195,   171,   182,  -195,
    -195,  -195,  -195,  -195,   246,   216,  -195,   275,  -195,  -195,
     109,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -194,  -195,  -195,  -195,  -195,   112,  -195,  -195,    74,
    -195,  -195,  -195,   342,  -195,  -195,  -195
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    80,   141,
      32,    58,    59,    60,    61,    33,    34,    35,    36,   137,
      37,    38,    39,    40,    41,    42,    43,    86,    87,   144,
      44,   189,    77,   113,    45,    46,   257,    47,   221,   222,
     223,   224,    48,   128,   129,   213,   249,   250,   293,   294,
     331,   295,    49,   171,   172,   175,   176,   177,   263,   307,
     262,   296,   208,   264,   315,   316,   346,   356,   357,   368,
     377,   359,   317,   349,   364,   318,   347,   360,   379,   380,
     308,   309,   310,    50,    51,    52,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    83,    70,    63,   130,    65,     5,    74,    66,   219,
      64,   383,    67,    84,    54,   242,   243,    75,     1,   358,
      79,   266,   375,   173,   145,     5,    68,   354,   174,   140,
       2,   108,   146,   109,   362,   372,     3,   337,     4,   371,
     355,   370,   266,   110,    69,   386,   241,   393,     5,     1,
     376,    17,   338,   387,    62,   266,    85,    63,   183,    65,
      76,     2,    66,   184,    64,   116,    67,   241,    16,     4,
     135,  -106,   132,    73,   320,   321,   322,   323,   324,   219,
    -107,   229,   241,   131,   230,   138,   169,   241,   136,    18,
      19,    20,   170,    21,    22,    23,    24,    79,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    71,   220,   166,
      18,    19,    20,   191,    21,    22,    23,    24,   192,    72,
     187,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   173,   206,   194,   195,   311,   174,   254,
     211,   212,     1,   197,   255,   363,   312,   313,   314,    81,
      78,   273,    79,   369,     2,   114,   274,     1,   -98,   -98,
       3,   121,     4,   236,   117,   122,     5,   237,   216,     2,
     119,   225,   384,   217,   227,   133,   265,     4,   220,   266,
     -97,   -97,   251,   267,   392,   118,   266,   226,   188,     7,
     109,   134,   228,    91,    92,    93,   233,   139,     8,     9,
      10,    11,    12,    13,   140,    55,    56,    57,    15,    16,
     142,    17,   143,    18,    19,    20,   178,    21,    22,    23,
      24,   123,   124,   125,   126,   127,   259,   179,    18,    19,
      20,   167,    21,    22,    23,    24,   111,   112,   180,   276,
     181,   278,   182,   280,   185,   193,   196,   287,   300,   279,
     288,   301,   290,   303,   199,   291,   304,   289,   302,   292,
     305,   200,     1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,     2,   326,   201,   202,   203,   328,
       3,   214,     4,   204,   205,     5,     5,   297,   209,    89,
      90,    91,    92,    93,   210,   381,    96,    97,    98,    99,
     215,   -91,   298,   299,   229,   285,   286,   231,   232,     7,
      89,    90,    91,    92,    93,   234,   238,   239,     8,     9,
      10,    11,    12,    13,     1,   240,   241,   252,    15,    16,
     253,    17,   268,    18,    19,    20,     2,    21,    22,    23,
      24,   256,     3,   353,     4,   261,   269,   270,     5,   284,
     287,   366,   271,   288,   272,   290,   275,   281,   291,   283,
     289,   282,   292,   327,   329,   332,   319,   285,   286,   330,
     333,     7,   244,   245,   246,   247,   248,   334,   335,   336,
       8,     9,    10,    11,    12,    13,     1,   339,   266,   340,
      15,    16,   341,    17,   344,    18,    19,    20,     2,    21,
      22,    23,    24,   342,     3,   345,     4,   348,   343,   350,
       5,   373,     8,     9,    10,    11,    12,    13,   351,   352,
     367,   378,    15,   382,   385,   388,   389,   390,    82,   285,
     286,   277,   120,     7,   325,   306,     1,   198,   235,   218,
     260,   207,     8,     9,    10,    11,    12,    13,     2,   365,
     361,   391,    15,    16,     3,    17,     4,    18,    19,    20,
       5,    21,    22,    23,    24,     0,   190,     6,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,     7,   102,   103,   104,   105,   106,   107,
       0,     0,     8,     9,    10,    11,    12,    13,    14,     0,
       0,     0,    15,    16,     0,    17,     0,    18,    19,    20,
       0,    21,    22,    23,    24,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,     0,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   374,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,     0,   102,   103,
     104,   105,   106,     0,     0,     0,   115,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,     0,   102,   103,   104,   105,   106,     0,     0,     0,
     186,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,     0,   102,   103,   104,   105,
     106,     0,     0,     0,   258,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,     0,
     102,   103,   104,   105,   106,   168,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
       0,   102,   103,   104,   105,   106
};

static const yytype_int16 yycheck[] =
{
       5,    28,     7,     5,    71,     5,    29,    25,     5,   185,
       5,    43,     5,    35,     4,   209,   210,    35,     5,    30,
      27,    31,    23,    37,    23,    29,    78,    30,    42,    27,
      17,    78,    31,    80,    30,    24,    23,    29,    25,    30,
      43,    51,    31,    37,    25,    23,    78,    23,    29,     5,
      51,    74,    44,    31,    59,    31,    78,    59,    26,    59,
      78,    17,    59,    31,    59,    55,    59,    78,    72,    25,
      26,    78,    74,    25,   268,   269,   270,   271,   272,   255,
      78,    28,    78,    73,    31,    79,    50,    78,    78,    76,
      77,    78,    56,    80,    81,    82,    83,    27,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    78,   185,   113,
      76,    77,    78,    26,    80,    81,    82,    83,    31,    78,
     132,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    37,    38,   139,   140,    30,    42,    26,
      58,    59,     5,   143,    31,   349,    39,    40,    41,     0,
      25,    23,    27,   357,    17,    32,    28,     5,    33,    34,
      23,    25,    25,    25,    23,    29,    29,    29,   183,    17,
      30,   186,   376,   183,   189,    78,    28,    25,   255,    31,
      33,    34,   219,    28,   388,    23,    31,   187,    78,    52,
      80,    75,   192,     6,     7,     8,   200,    27,    61,    62,
      63,    64,    65,    66,    27,    68,    69,    70,    71,    72,
      78,    74,     3,    76,    77,    78,     3,    80,    81,    82,
      83,    53,    54,    55,    56,    57,   230,     3,    76,    77,
      78,    78,    80,    81,    82,    83,    33,    34,     3,   254,
       3,   256,     3,   258,    25,    28,     3,   262,   263,   256,
     262,   263,   262,   263,     3,   262,   263,   262,   263,   262,
     263,     3,     5,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    17,   275,    26,    31,    78,   283,
      23,    80,    25,    78,    30,    29,    29,    30,    27,     4,
       5,     6,     7,     8,    27,   372,    11,    12,    13,    14,
      27,    29,    45,    46,    28,    48,    49,    78,    82,    52,
       4,     5,     6,     7,     8,    29,    29,    23,    61,    62,
      63,    64,    65,    66,     5,    29,    78,    35,    71,    72,
      78,    74,    24,    76,    77,    78,    17,    80,    81,    82,
      83,    73,    23,   343,    25,    56,    24,    24,    29,    30,
     365,   351,    24,   365,    24,   365,     3,    28,   365,     3,
     365,    30,   365,    23,    29,    23,    78,    48,    49,    25,
      23,    52,     4,     5,     6,     7,     8,    78,    78,    29,
      61,    62,    63,    64,    65,    66,     5,    29,    31,    26,
      71,    72,    78,    74,    23,    76,    77,    78,    17,    80,
      81,    82,    83,    43,    23,    23,    25,    29,    47,    29,
      29,    30,    61,    62,    63,    64,    65,    66,    31,    26,
      51,    78,    71,    51,    60,    51,    78,    23,    27,    48,
      49,   255,    59,    52,   273,   263,     5,   146,   202,   184,
     234,   176,    61,    62,    63,    64,    65,    66,    17,   350,
     348,   387,    71,    72,    23,    74,    25,    76,    77,    78,
      29,    80,    81,    82,    83,    -1,   134,    36,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    52,    18,    19,    20,    21,    22,    23,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    -1,    74,    -1,    76,    77,    78,
      -1,    80,    81,    82,    83,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    26,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      26,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    26,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    17,    23,    25,    29,    36,    52,    61,    62,
      63,    64,    65,    66,    67,    71,    72,    74,    76,    77,
      78,    80,    81,    82,    83,    85,    86,    87,    88,    89,
      90,    91,    94,    99,   100,   101,   102,   104,   105,   106,
     107,   108,   109,   110,   114,   118,   119,   121,   126,   136,
     167,   168,   169,   170,   101,    68,    69,    70,    95,    96,
      97,    98,    99,   100,   110,   114,   119,   126,    78,    25,
      99,    78,    78,    25,    25,    35,    78,   116,    25,    27,
      92,     0,    94,    92,    35,    78,   111,   112,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    18,    19,    20,    21,    22,    23,    78,    80,
     118,    33,    34,   117,    32,    26,   101,    23,    23,    30,
      97,    25,    29,    53,    54,    55,    56,    57,   127,   128,
      89,   101,   100,    78,    75,    26,   101,   103,   118,    27,
      27,    93,    78,     3,   113,    23,    31,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   118,    78,    23,    50,
      56,   137,   138,    37,    42,   139,   140,   141,     3,     3,
       3,     3,     3,    26,    31,    25,    26,   100,    78,   115,
     167,    26,    31,    28,   118,   118,     3,   101,   112,     3,
       3,    26,    31,    78,    78,    30,    38,   141,   146,    27,
      27,    58,    59,   129,    80,    27,    99,   114,   128,    88,
      89,   122,   123,   124,   125,    99,   101,    99,   101,    28,
      31,    78,    82,   118,    29,   138,    25,    29,    29,    23,
      29,    78,   155,   155,     4,     5,     6,     7,     8,   130,
     131,    92,    35,    78,    26,    31,    73,   120,    26,   118,
     139,    56,   144,   142,   147,    28,    31,    28,    24,    24,
      24,    24,    24,    23,    28,     3,    99,   125,    99,   119,
      99,    28,    30,     3,    30,    48,    49,    99,   100,   110,
     114,   119,   126,   132,   133,   135,   145,    30,    45,    46,
      99,   100,   110,   114,   119,   126,   132,   143,   164,   165,
     166,    30,    39,    40,    41,   148,   149,   156,   159,    78,
     155,   155,   155,   155,   155,   131,   101,    23,   118,    29,
      25,   134,    23,    23,    78,    78,    29,    29,    44,    29,
      26,    78,    43,    47,    23,    23,   150,   160,    29,   157,
      29,    31,    26,   101,    30,    43,   151,   152,    30,   155,
     161,   160,    30,   155,   158,   144,   101,    51,   153,   155,
      51,    30,    24,    30,    30,    23,    51,   154,    78,   162,
     163,    89,    51,    43,   155,    60,    23,    31,    51,    78,
      23,   163,   155,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    91,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    97,    97,    97,
      97,    98,    98,    98,    99,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   103,   103,   103,
     104,   104,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   106,   106,   107,   108,   108,   108,   108,   108,   108,
     109,   109,   110,   111,   111,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   120,   121,   122,   122,   123,   123,   124,   124,
     124,   125,   125,   126,   126,   126,   127,   127,   128,   128,
     128,   128,   128,   129,   129,   130,   130,   131,   131,   131,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   140,   140,
     141,   141,   141,   142,   142,   143,   143,   143,   143,   143,
     143,   143,   143,   144,   144,   145,   145,   145,   145,   145,
     145,   145,   146,   146,   147,   147,   148,   148,   148,   149,
     150,   150,   151,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   157,   157,   158,   159,   159,   160,   160,   161,
     162,   162,   163,   163,   164,   164,   165,   166,   167,   168,
     168,   168,   168,   168,   168,   168,   169,   169,   169,   170,
     170
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     3,     2,     4,     3,
       5,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     3,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     1,     0,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     4,     2,     2,     0,     7,
       5,     1,     1,     1,     2,     1,     1,     1,     1,     6,
       7,     2,     0,     7,     1,     2,     1,     2,     3,     1,
       0,     2,     4,     5,     2,     5,     3,     1,     5,     5,
       5,     3,     3,     1,     1,     3,     1,     3,     3,     3,
       3,     3,     2,     2,     4,     2,     3,     0,     6,     8,
       9,     6,     3,     1,     3,     3,     2,     0,     2,     1,
       5,    10,     5,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     2,     0,     1,     1,     1,     4,
       2,     0,     3,     2,     0,     3,     1,     3,     1,     3,
       1,     4,     2,     0,     6,     4,     5,     2,     0,     4,
       3,     1,     1,     2,     1,     1,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statement_list  */
#line 43 "parser.y"
                        {printf("Program is correct\n");}
#line 2073 "y.tab.c"
    break;


#line 2077 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 517 "parser.y"

int main(void) {
	yyparse();
}

