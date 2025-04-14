/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_USERS_TANG_COURSE_LAB_PASCAL2C_SRC_PASCAL_PARSER_HPP_INCLUDED
# define YY_YY_USERS_TANG_COURSE_LAB_PASCAL2C_SRC_PASCAL_PARSER_HPP_INCLUDED
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
    T_PROGRAM = 258,               /* T_PROGRAM  */
    T_BEGIN = 259,                 /* T_BEGIN  */
    T_END = 260,                   /* T_END  */
    T_VAR = 261,                   /* T_VAR  */
    T_FUNCTION = 262,              /* T_FUNCTION  */
    T_PROCEDURE = 263,             /* T_PROCEDURE  */
    T_IF = 264,                    /* T_IF  */
    T_THEN = 265,                  /* T_THEN  */
    T_ELSE = 266,                  /* T_ELSE  */
    T_WHILE = 267,                 /* T_WHILE  */
    T_DO = 268,                    /* T_DO  */
    T_FOR = 269,                   /* T_FOR  */
    T_TO = 270,                    /* T_TO  */
    T_DOWNTO = 271,                /* T_DOWNTO  */
    T_REPEAT = 272,                /* T_REPEAT  */
    T_UNTIL = 273,                 /* T_UNTIL  */
    T_CASE = 274,                  /* T_CASE  */
    T_OF = 275,                    /* T_OF  */
    T_CONST = 276,                 /* T_CONST  */
    T_TYPE = 277,                  /* T_TYPE  */
    T_ARRAY = 278,                 /* T_ARRAY  */
    T_RECORD = 279,                /* T_RECORD  */
    T_DIV = 280,                   /* T_DIV  */
    T_MOD = 281,                   /* T_MOD  */
    T_AND = 282,                   /* T_AND  */
    T_OR = 283,                    /* T_OR  */
    T_NOT = 284,                   /* T_NOT  */
    T_ASSIGN = 285,                /* T_ASSIGN  */
    T_PLUS = 286,                  /* T_PLUS  */
    T_MINUS = 287,                 /* T_MINUS  */
    T_MULTIPLY = 288,              /* T_MULTIPLY  */
    T_DIVIDE = 289,                /* T_DIVIDE  */
    T_EQUAL = 290,                 /* T_EQUAL  */
    T_NOT_EQUAL = 291,             /* T_NOT_EQUAL  */
    T_LESS = 292,                  /* T_LESS  */
    T_LESS_EQUAL = 293,            /* T_LESS_EQUAL  */
    T_GREATER = 294,               /* T_GREATER  */
    T_GREATER_EQUAL = 295,         /* T_GREATER_EQUAL  */
    T_LPAREN = 296,                /* T_LPAREN  */
    T_RPAREN = 297,                /* T_RPAREN  */
    T_LBRACKET = 298,              /* T_LBRACKET  */
    T_RBRACKET = 299,              /* T_RBRACKET  */
    T_COLON = 300,                 /* T_COLON  */
    T_SEMICOLON = 301,             /* T_SEMICOLON  */
    T_COMMA = 302,                 /* T_COMMA  */
    T_DOT = 303,                   /* T_DOT  */
    T_DOTDOT = 304,                /* T_DOTDOT  */
    T_IDENTIFIER = 305,            /* T_IDENTIFIER  */
    T_TYPE_ID = 306,               /* T_TYPE_ID  */
    T_INT_CONST = 307,             /* T_INT_CONST  */
    T_REAL_CONST = 308,            /* T_REAL_CONST  */
    T_STRING_CONST = 309,          /* T_STRING_CONST  */
    T_BOOL_CONST = 310             /* T_BOOL_CONST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.y"

    bool boolVal;
    int intVal;
    double realVal;
    char* strVal;
    class ASTNode* node;
    class ProgramNode* programNode;
    class VarDeclNode* varDeclNode;
    class BinaryOpNode* binaryOpNode;
    class IdentifierNode* identifierNode;
    class LiteralNode* literalNode;
    class AssignNode* assignNode;
    class IfNode* ifNode;
    class WhileNode* whileNode;
    class ProcCallNode* procCallNode;

#line 136 "/Users/tang/Course/编译原理课程设计/lab/Pascal2C/src/pascal_parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_USERS_TANG_COURSE_LAB_PASCAL2C_SRC_PASCAL_PARSER_HPP_INCLUDED  */
