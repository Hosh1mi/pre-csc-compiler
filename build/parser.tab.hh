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

#ifndef YY_YY_BUILD_PARSER_TAB_HH_INCLUDED
# define YY_YY_BUILD_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

#include "ast.h"

#line 53 "build/parser.tab.hh"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    VOID = 260,                    /* VOID  */
    CONST = 261,                   /* CONST  */
    RETURN = 262,                  /* RETURN  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    WHILE = 265,                   /* WHILE  */
    BREAK = 266,                   /* BREAK  */
    CONTINUE = 267,                /* CONTINUE  */
    LP = 268,                      /* LP  */
    RP = 269,                      /* RP  */
    LB = 270,                      /* LB  */
    RB = 271,                      /* RB  */
    LC = 272,                      /* LC  */
    RC = 273,                      /* RC  */
    COMMA = 274,                   /* COMMA  */
    SEMICOLON = 275,               /* SEMICOLON  */
    QUESTION = 276,                /* QUESTION  */
    COLON = 277,                   /* COLON  */
    MINUS = 278,                   /* MINUS  */
    NOT = 279,                     /* NOT  */
    TILDE = 280,                   /* TILDE  */
    ASSIGN = 281,                  /* ASSIGN  */
    ADD = 282,                     /* ADD  */
    MUL = 283,                     /* MUL  */
    DIV = 284,                     /* DIV  */
    MOD = 285,                     /* MOD  */
    AND = 286,                     /* AND  */
    OR = 287,                      /* OR  */
    EQ = 288,                      /* EQ  */
    NE = 289,                      /* NE  */
    LT = 290,                      /* LT  */
    LE = 291,                      /* LE  */
    GT = 292,                      /* GT  */
    GE = 293,                      /* GE  */
    ID = 294,                      /* ID  */
    INT_LIT = 295,                 /* INT_LIT  */
    FLOAT_LIT = 296,               /* FLOAT_LIT  */
    LEX_ERR = 297,                 /* LEX_ERR  */
    UMINUS = 298                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "src/parser.y"
 char* str; ASTNode* node; 

#line 116 "build/parser.tab.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_TAB_HH_INCLUDED  */
