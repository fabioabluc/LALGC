
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFICADOR = 258,
     NUMERO_INTEIRO = 259,
     NUMERO_REAL = 260,
     BEGN = 261,
     DO = 262,
     ELSE = 263,
     END = 264,
     IF = 265,
     INTEGER = 266,
     PROCEDURE = 267,
     PROGRAM = 268,
     READ = 269,
     REAL = 270,
     REPEAT = 271,
     THEN = 272,
     UNTIL = 273,
     VAR = 274,
     WHILE = 275,
     WRITE = 276,
     A_PAR = 277,
     F_PAR = 278,
     VZS = 279,
     MAIS = 280,
     VIRG = 281,
     MENOS = 282,
     PONTO = 283,
     DIV = 284,
     RECEBE = 285,
     DP = 286,
     PV = 287,
     DIF = 288,
     MENORI = 289,
     MENOR = 290,
     IGUAL = 291,
     MAIORI = 292,
     MAIOR = 293,
     IDENTIFICADOR_NAO_ENCONTRADO = 294,
     FIM_DA_ANALISE = 295
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 23 "sintatico.y"

	char text[50];
	int integer;
	float real;



/* Line 1676 of yacc.c  */
#line 100 "sintatico.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


