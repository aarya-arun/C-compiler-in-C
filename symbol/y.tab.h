/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    CHAR = 261,
    ID = 262,
    NUM = 263,
    REAL = 264,
    WHILE = 265,
    IF = 266,
    RETURN = 267,
    PREPROC = 268,
    LE = 269,
    STRING = 270,
    PRINT = 271,
    FUNCTION = 272,
    DO = 273,
    ARRAY = 274,
    ELSE = 275,
    STRUCT = 276,
    STRUCT_VAR = 277,
    FOR = 278,
    GE = 279,
    EQ = 280,
    NE = 281,
    INC = 282,
    DEC = 283,
    DEFAULT = 284,
    BREAK = 285,
    CASE = 286,
    SWITCH = 287
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define CHAR 261
#define ID 262
#define NUM 263
#define REAL 264
#define WHILE 265
#define IF 266
#define RETURN 267
#define PREPROC 268
#define LE 269
#define STRING 270
#define PRINT 271
#define FUNCTION 272
#define DO 273
#define ARRAY 274
#define ELSE 275
#define STRUCT 276
#define STRUCT_VAR 277
#define FOR 278
#define GE 279
#define EQ 280
#define NE 281
#define INC 282
#define DEC 283
#define DEFAULT 284
#define BREAK 285
#define CASE 286
#define SWITCH 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "parser.y" /* yacc.c:1909  */

	int ival;
	char *str;

#line 123 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
