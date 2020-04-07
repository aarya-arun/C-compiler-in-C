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
    DOT = 258,
    SINGLE = 259,
    SC = 260,
    COMMA = 261,
    LETTER = 262,
    OPBRACE = 263,
    CLBRACE = 264,
    CONTINUE = 265,
    BREAK = 266,
    IF = 267,
    ELSE = 268,
    FOR = 269,
    WHILE = 270,
    POW = 271,
    OPEN = 272,
    CLOSE = 273,
    COMMENT = 274,
    INT = 275,
    FLOAT = 276,
    CHAR = 277,
    ID = 278,
    NUM = 279,
    PLUS = 280,
    MINUS = 281,
    MULT = 282,
    DIV = 283,
    AND = 284,
    OR = 285,
    LESS = 286,
    GREAT = 287,
    LESEQ = 288,
    GRTEQ = 289,
    NOTEQ = 290,
    EQEQ = 291,
    ASSIGN = 292,
    SPLUS = 293,
    SMINUS = 294,
    SMULT = 295,
    SDIV = 296,
    INC = 297,
    DEC = 298,
    SWITCH = 299,
    MAIN = 300,
    RETURN = 301,
    DEFAULT = 302,
    CASE = 303,
    COLON = 304
  };
#endif
/* Tokens.  */
#define DOT 258
#define SINGLE 259
#define SC 260
#define COMMA 261
#define LETTER 262
#define OPBRACE 263
#define CLBRACE 264
#define CONTINUE 265
#define BREAK 266
#define IF 267
#define ELSE 268
#define FOR 269
#define WHILE 270
#define POW 271
#define OPEN 272
#define CLOSE 273
#define COMMENT 274
#define INT 275
#define FLOAT 276
#define CHAR 277
#define ID 278
#define NUM 279
#define PLUS 280
#define MINUS 281
#define MULT 282
#define DIV 283
#define AND 284
#define OR 285
#define LESS 286
#define GREAT 287
#define LESEQ 288
#define GRTEQ 289
#define NOTEQ 290
#define EQEQ 291
#define ASSIGN 292
#define SPLUS 293
#define SMINUS 294
#define SMULT 295
#define SDIV 296
#define INC 297
#define DEC 298
#define SWITCH 299
#define MAIN 300
#define RETURN 301
#define DEFAULT 302
#define CASE 303
#define COLON 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "ast.y" /* yacc.c:1909  */
char* var_type; char* text; struct AST *node;

#line 155 "y.tab.h" /* yacc.c:1909  */
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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
