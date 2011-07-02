
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "sintatico.y"

#include <stdio.h>
#include "util/Simble.h"
#include "util/Table.h"

// Numero da linha
int lineno = 1;
// Booleana para erros sintaticos
int synerr = 0;
// Booleana para reportar erros
int reperr = 0;
// Tabela de simbolos
Table *TS = NULL;

int yylex (void);
void yywrap(void);
void yyerror(const char *);
void errmsg(const char *msg);



/* Line 189 of yacc.c  */
#line 95 "sintatico.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 23 "sintatico.y"

	char text[50];
	int integer;
	float real;



/* Line 214 of yacc.c  */
#line 179 "sintatico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 191 "sintatico.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    10,    16,    17,    22,    23,    30,
      35,    42,    43,    49,    52,    59,    60,    61,    69,    70,
      78,    81,    83,    85,    87,    88,    92,    95,    96,   103,
     104,   105,   113,   117,   118,   122,   127,   130,   131,   137,
     138,   145,   146,   153,   155,   159,   160,   163,   166,   167,
     170,   171,   175,   176,   181,   186,   191,   196,   202,   205,
     209,   211,   212,   219,   222,   224,   228,   230,   232,   234,
     236,   238,   240,   242,   245,   247,   249,   251,   252,   256,
     257,   260,   262,   264,   268,   272,   273,   275,   277,   278,
     280,   282,   284,   288,   290,   292,   294,   296,   298,   300,
     302,   304,   306
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    13,     3,    84,    47,    85,    -1,    -1,
       1,    44,    32,    47,    85,    -1,    -1,     1,    45,    47,
      85,    -1,    -1,    13,     1,    46,    84,    47,    85,    -1,
      49,     6,    70,     9,    -1,    49,     6,    70,    32,     1,
      28,    -1,    -1,    49,     1,    48,    70,     9,    -1,    50,
      57,    -1,    19,    54,    86,    53,    32,    50,    -1,    -1,
      -1,    19,    54,    86,     1,    32,    51,    50,    -1,    -1,
      19,    54,    86,    53,     1,    52,    50,    -1,    19,     1,
      -1,    15,    -1,    11,    -1,     1,    -1,    -1,     3,    55,
      56,    -1,    26,    54,    -1,    -1,    12,     3,    59,    84,
      62,    57,    -1,    -1,    -1,    12,     3,     1,    41,    58,
      62,    57,    -1,    87,    60,    88,    -1,    -1,    22,     1,
      23,    -1,    54,    86,    53,    61,    -1,    32,    60,    -1,
      -1,    65,     6,    70,     9,    84,    -1,    -1,     1,     6,
      63,    70,     9,    84,    -1,    -1,    65,     1,    64,    70,
       9,    84,    -1,    50,    -1,    87,    67,    88,    -1,    -1,
       3,    68,    -1,    32,    67,    -1,    -1,     8,    71,    -1,
      -1,    71,    32,    70,    -1,    -1,    14,    87,    54,    88,
      -1,    21,    87,    54,    88,    -1,    20,    74,     7,    71,
      -1,    16,    71,    18,    74,    -1,    10,    74,    17,    71,
      69,    -1,     3,    73,    -1,     6,    70,     9,    -1,     1,
      -1,    -1,    10,    74,     1,    72,    71,    69,    -1,    30,
      76,    -1,    66,    -1,    76,    75,    76,    -1,     1,    -1,
      36,    -1,    33,    -1,    37,    -1,    34,    -1,    38,    -1,
      35,    -1,    80,    78,    -1,     1,    -1,    25,    -1,    27,
      -1,    -1,    79,    80,    78,    -1,    -1,    79,     1,    -1,
      25,    -1,    27,    -1,    77,    83,    81,    -1,    82,    83,
      81,    -1,    -1,    24,    -1,    29,    -1,    -1,     3,    -1,
       4,    -1,     5,    -1,    22,    76,    88,    -1,    32,    -1,
       1,    -1,    28,    -1,     1,    -1,    31,    -1,     1,    -1,
      22,    -1,     1,    -1,    23,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    83,    83,    84,    84,    85,    85,    88,
      90,    91,    91,    94,    97,    97,   100,   100,   101,   101,
     102,   105,   106,   107,   111,   110,   120,   120,   124,   124,
     127,   127,   130,   130,   133,   136,   139,   139,   143,   145,
     145,   146,   146,   149,   152,   152,   156,   159,   159,   163,
     163,   167,   167,   171,   172,   173,   174,   175,   176,   177,
     179,   180,   180,   183,   184,   187,   189,   192,   193,   194,
     195,   196,   197,   200,   202,   205,   206,   206,   210,   210,
     213,   216,   217,   220,   223,   223,   227,   228,   228,   230,
     231,   232,   233,   237,   238,   241,   242,   245,   246,   249,
     250,   253,   254
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFICADOR", "NUMERO_INTEIRO",
  "NUMERO_REAL", "BEGN", "DO", "ELSE", "END", "IF", "INTEGER", "PROCEDURE",
  "PROGRAM", "READ", "REAL", "REPEAT", "THEN", "UNTIL", "VAR", "WHILE",
  "WRITE", "A_PAR", "F_PAR", "VZS", "MAIS", "VIRG", "MENOS", "PONTO",
  "DIV", "RECEBE", "DP", "PV", "DIF", "MENORI", "MENOR", "IGUAL", "MAIORI",
  "MAIOR", "IDENTIFICADOR_NAO_ENCONTRADO", "FIM_DA_ANALISE", "'\\n'",
  "$accept", "programa", "$@1", "$@2", "$@3", "corpo", "$@4", "dc", "dc_v",
  "$@5", "$@6", "tipo_var", "variaveis", "$@7", "mais_var", "dc_p", "$@8",
  "parametros", "lista_par", "mais_par", "corpo_p", "$@9", "$@10",
  "dc_loc", "lista_arg", "argumentos", "mais_ident", "pfalsa", "comandos",
  "cmd", "$@11", "id_cont", "condicao", "relacao", "expressao", "op_un",
  "outros_termos", "op_ad", "termo", "mais_fatores", "op_mul", "fator",
  "pv", "ponto", "dp", "a_par", "f_par", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    43,    45,    43,    46,    43,    47,
      47,    48,    47,    49,    50,    50,    51,    50,    52,    50,
      50,    53,    53,    53,    55,    54,    56,    56,    57,    57,
      58,    57,    59,    59,    59,    60,    61,    61,    62,    63,
      62,    64,    62,    65,    66,    66,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    71,    73,    73,    74,    74,    75,    75,    75,
      75,    75,    75,    76,    76,    77,    77,    77,    78,    78,
      78,    79,    79,    80,    81,    81,    82,    82,    82,    83,
      83,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     5,     0,     4,     0,     6,     4,
       6,     0,     5,     2,     6,     0,     0,     7,     0,     7,
       2,     1,     1,     1,     0,     3,     2,     0,     6,     0,
       0,     7,     3,     0,     3,     4,     2,     0,     5,     0,
       6,     0,     6,     1,     3,     0,     2,     2,     0,     2,
       0,     3,     0,     4,     4,     4,     4,     5,     2,     3,
       1,     0,     6,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     0,     3,     0,
       2,     1,     1,     3,     3,     0,     1,     1,     0,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     0,    15,     7,     0,     1,    15,
       0,     0,     0,    29,     0,    94,    93,    15,     0,    20,
      24,     0,    96,    95,     6,    11,     0,     0,    13,    15,
       0,     4,    27,    98,    97,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,    25,    23,    22,    21,     0,     0,   100,    99,     0,
      64,    58,     0,     0,    66,    75,    76,     0,     0,     0,
      79,     0,     0,     0,     0,     9,     0,     0,   100,     0,
       0,     0,     8,    26,    16,    18,    15,    12,    74,    63,
      48,     0,    59,    61,     0,    68,    70,    72,    67,    69,
      71,     0,    89,    90,    91,     0,    85,    81,    82,    73,
       0,     0,     0,     0,     0,     0,    51,    30,     0,     0,
       0,     0,    15,    15,    14,     0,    46,   102,   101,    44,
       0,    50,    65,     0,    86,    87,    83,     0,    80,    79,
      53,    56,    55,    54,    10,     0,    34,     0,    43,    29,
       0,     0,    32,    17,    19,    47,    50,     0,    57,    92,
      85,    78,    29,    39,    28,    41,     0,    23,    37,    62,
      49,    84,    31,     0,     0,     0,     0,    35,     0,     0,
       0,    36,     0,     0,    38,    40,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    14,    11,    36,    12,    13,   122,
     123,    55,   120,    32,    51,    28,   145,    80,   121,   177,
     149,   173,   174,   150,    60,    91,   126,   158,    45,    46,
     130,    61,    67,   101,    68,    69,   109,   110,    70,   136,
     137,   106,    17,    24,    35,    62,   129
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -81
static const yytype_int16 yypact[] =
{
      99,    -1,   132,    32,    25,    46,   -81,     5,   -81,    46,
     151,    23,    70,    86,     5,   -81,   -81,    46,    23,   -81,
     -81,    24,   -81,   -81,   -81,   -81,     7,   100,   -81,    46,
      23,   -81,    81,   -81,   -81,    80,   120,   -81,    28,   120,
      58,    67,   141,    58,    67,     3,    72,     8,    23,   -81,
     111,   -81,    88,   -81,   -81,    13,   106,   -81,   -81,    74,
     -81,   -81,   121,   123,   142,   -81,   -81,    55,   148,   145,
     118,   111,   109,   130,   111,   -81,   152,     7,   105,   155,
       5,   111,   -81,   -81,   -81,   -81,    46,   -81,   -81,   -81,
     127,    18,   -81,   -81,   141,   -81,   -81,   -81,   -81,   -81,
     -81,    74,   -81,   -81,   -81,    74,    89,   -81,   -81,   -81,
      83,    18,    58,   141,    18,   135,   -81,   -81,   149,    14,
      24,    18,    46,    46,   -81,   121,   -81,   -81,   -81,   -81,
     141,   156,   -81,    18,   -81,   -81,   -81,   145,   -81,   118,
     -81,   -81,   -81,   -81,   -81,    14,   -81,   165,   -81,    86,
      96,   159,   -81,   -81,   -81,   -81,   156,   141,   -81,   -81,
      89,   -81,    86,   -81,   -81,   -81,   120,   -81,   133,   -81,
     -81,   -81,   -81,   120,   120,   164,   111,   -81,   178,   179,
       5,   -81,     5,     5,   -81,   -81,   -81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,   -81,   -81,     9,   -81,   -81,   -75,   -81,
     -81,    38,    -7,   -81,   -81,   -80,   -81,   -81,    15,   -81,
      45,   -81,   -81,   -81,   -81,    68,   -81,    36,   -35,   -40,
     -81,   -81,   -38,   -81,   -52,   -81,    56,   -81,    84,    37,
     -81,    59,   -14,     4,    79,    78,    -5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -100
static const yytype_int16 yytable[] =
{
      29,    56,    72,    21,    63,    73,    15,    89,    37,    78,
      38,   124,    75,    39,    85,   147,   -52,    40,    18,   127,
     -15,    41,    31,    42,    22,    33,    30,    43,    44,    57,
      79,    -3,     8,    10,    49,    76,   -45,    16,    48,   -52,
     -33,   128,   116,    83,   148,    86,   -45,   153,   154,   132,
      58,    23,    82,   133,   131,    34,    93,     9,    59,    64,
     -45,   -77,   -77,   -77,   111,    10,   119,   114,    57,   164,
     148,    25,    94,   142,   141,    88,    26,   -77,   -77,   -77,
     -77,    52,   172,    65,   138,    66,   -77,   -77,   -77,    58,
     156,    53,   -88,   -88,   -88,    54,   -77,   165,    27,    65,
       1,    66,   166,    47,    77,   -77,   140,    50,    65,   143,
      66,   -88,     2,   134,    20,    87,   152,   170,   135,    71,
      84,    37,    74,    38,    90,    81,    39,   112,   159,   -52,
      40,   175,    92,     6,    41,     7,    42,   113,   178,   179,
      43,    44,    37,   107,    38,   108,   117,    39,   102,   103,
     104,    40,    19,   115,    20,    41,   118,    42,   -99,   125,
     167,    43,    44,   144,   157,   176,   184,   105,   185,   186,
      53,   163,   146,   180,    54,   -74,   -74,   -74,   -74,   -74,
     -74,    95,    96,    97,    98,    99,   100,   182,   183,   168,
     162,   181,   169,   155,   139,   161,   160,   171,     0,   151
};

static const yytype_int16 yycheck[] =
{
      14,    36,    42,    10,    39,    43,     1,    59,     1,     1,
       3,    86,     9,     6,     1,     1,     9,    10,     9,     1,
       6,    14,    18,    16,     1,     1,    17,    20,    21,     1,
      22,    32,     0,    19,    30,    32,     8,    32,    29,    32,
      32,    23,    77,    50,   119,    32,    18,   122,   123,   101,
      22,    28,    48,   105,    94,    31,     1,    32,    30,     1,
      32,     3,     4,     5,    71,    19,    80,    74,     1,   149,
     145,     1,    17,   113,   112,     1,     6,     3,     4,     5,
      22,     1,   162,    25,     1,    27,     3,     4,     5,    22,
     130,    11,     3,     4,     5,    15,    22,     1,    12,    25,
       1,    27,     6,     3,    32,    22,   111,    26,    25,   114,
      27,    22,    13,    24,     3,     9,   121,   157,    29,    41,
      32,     1,    44,     3,     3,    47,     6,    18,   133,     9,
      10,   166,     9,     1,    14,     3,    16,     7,   173,   174,
      20,    21,     1,    25,     3,    27,    41,     6,     3,     4,
       5,    10,     1,     1,     3,    14,     1,    16,     3,    32,
       1,    20,    21,    28,     8,    32,   180,    22,   182,   183,
      11,     6,    23,     9,    15,    33,    34,    35,    36,    37,
      38,    33,    34,    35,    36,    37,    38,     9,     9,   151,
     145,   176,   156,   125,   110,   139,   137,   160,    -1,   120
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    13,    43,    44,    45,     1,     3,     0,    32,
      19,    47,    49,    50,    46,     1,    32,    84,    47,     1,
       3,    54,     1,    28,    85,     1,     6,    12,    57,    84,
      47,    85,    55,     1,    31,    86,    48,     1,     3,     6,
      10,    14,    16,    20,    21,    70,    71,     3,    47,    85,
      26,    56,     1,    11,    15,    53,    70,     1,    22,    30,
      66,    73,    87,    70,     1,    25,    27,    74,    76,    77,
      80,    87,    71,    74,    87,     9,    32,    32,     1,    22,
      59,    87,    85,    54,    32,     1,    32,     9,     1,    76,
       3,    67,     9,     1,    17,    33,    34,    35,    36,    37,
      38,    75,     3,     4,     5,    22,    83,    25,    27,    78,
      79,    54,    18,     7,    54,     1,    70,    41,     1,    84,
      54,    60,    51,    52,    50,    32,    68,     1,    23,    88,
      72,    71,    76,    76,    24,    29,    81,    82,     1,    80,
      88,    74,    71,    88,    28,    58,    23,     1,    50,    62,
      65,    86,    88,    50,    50,    67,    71,     8,    69,    88,
      83,    78,    62,     6,    57,     1,     6,     1,    53,    69,
      71,    81,    57,    63,    64,    70,    32,    61,    70,    70,
       9,    60,     9,     9,    84,    84,    84
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 83 "sintatico.y"
    { if (reperr) errmsg("'program' esperado."); reperr = 0; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 84 "sintatico.y"
    { if (reperr) errmsg("'program' esperado."); reperr = 0; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 85 "sintatico.y"
    { if (reperr) errmsg("Identificador esperado."); reperr = 0; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 90 "sintatico.y"
    { if (reperr) errmsg("'end' esperado."); reperr = 0; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 91 "sintatico.y"
    { if (reperr) errmsg("'begin' esperado.");  yyclearin; yyerrok; reperr = 0; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 100 "sintatico.y"
    { if (reperr) errmsg("Tipo invalido."); yyerrok; reperr = 0; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 101 "sintatico.y"
    { if (reperr) errmsg("';' faltando depois da declaracao de variavel."); yyerrok; reperr = 0; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 102 "sintatico.y"
    { if (reperr) errmsg("Declaracao de variavel invalida."); reperr = 0; ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 107 "sintatico.y"
    { if (reperr) errmsg("Tipo inválido."); reperr = 0; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 111 "sintatico.y"
    {// Procura na tabela de simbolos
			printf("IDENTIFICADOR: %s\n",yylval.text);
			if (TableSearch(TS,yylval.text) != -1) {
				
			}
		;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 127 "sintatico.y"
    { if (reperr) errmsg("Parametros nao reconhecidos."); reperr = 0; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 133 "sintatico.y"
    { if (reperr) errmsg("Parametros nao reconhecidos."); reperr = 0; ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 145 "sintatico.y"
    { if (reperr) errmsg("Declaracao local nao reconhecida."); reperr = 0; ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 146 "sintatico.y"
    { if (reperr) errmsg("'begin' do procedimento esperado."); yyerrok; reperr = 0; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 179 "sintatico.y"
    { if (reperr) errmsg("Comando não reconhecido."); yyclearin; reperr = 0; ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 180 "sintatico.y"
    { if (reperr) errmsg("'then' esperado."); yyerrok; reperr = 0; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 189 "sintatico.y"
    { if (reperr) errmsg("Condicao invalida."); reperr = 0; ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 202 "sintatico.y"
    { if (reperr) errmsg("Expressao invalida."); reperr = 0; ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 213 "sintatico.y"
    { if (reperr) errmsg("Operacao invalida."); yyerrok; reperr = 0; ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 238 "sintatico.y"
    { if (reperr) errmsg("';' esperado."); yyerrok; reperr = 0; ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 242 "sintatico.y"
    { if (reperr) errmsg("'.' esperado."); reperr = 0; ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 246 "sintatico.y"
    { if (reperr) errmsg("':' esperado."); reperr = 0; ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 250 "sintatico.y"
    { if (reperr) errmsg("'(' esperado."); reperr = 0; ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 254 "sintatico.y"
    { if (reperr) errmsg("')' esperado."); reperr = 0; ;}
    break;



/* Line 1455 of yacc.c  */
#line 1730 "sintatico.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 256 "sintatico.y"

// Chamada quando encontra um fim de arquivo
void yywrap(void) {
	fflush(stderr);
	fprintf(stdout, "FIM DA ANALISE"); fflush(stdout);
	if (synerr) {
		fprintf(stdout,": 'syntax error'\n");
	} else {
		fprintf(stdout,": Compilacao concluida com sucesso.\n");
	}
}
// Chamada quando encontra um erro
void yyerror(const char *s) {
	synerr = 1;
	reperr = 1;
	//fprintf(stderr, "YYError:%d: %s\n", lineno, s);
}
void errmsg(const char *msg) {
	fprintf(stderr, "Erro:%d: %s\n", lineno, msg);
}


