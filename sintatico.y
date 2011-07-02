/* Pre-declaracao de includes e assinaturas de funcoes do lex */
%{
#include <stdio.h>

// Numero da linha
int lineno = 1;
// Booleana para erros sintaticos
int synerr = 0;
// Booleana para reportar erros
int reperr = 0;

int yylex (void);
void yywrap(void);
void yyerror(const char *);
void errmsg(const char *msg);
%}

/* Declaracao de tipos de tokens */
%token IDENTIFICADOR
%token NUMERO_INTEIRO
%token NUMERO_REAL
%token BEGN
%token DO
%token ELSE
%token END
%token IF
%token INTEGER
%token PROCEDURE
%token PROGRAM
%token READ
%token REAL
%token REPEAT
%token THEN
%token UNTIL
%token VAR
%token WHILE
%token WRITE
%token A_PAR
%token F_PAR
%token VZS
%token MAIS
%token VIRG
%token MENOS
%token PONTO
%token DIV
%token RECEBE
%token DP
%token PV
%token DIF
%token MENORI
%token MENOR
%token IGUAL
%token MAIORI
%token MAIOR
%token IDENTIFICADOR_NAO_ENCONTRADO
%token FIM_DA_ANALISE

/* Supressor de mensagens de shift/reduce */
%expect 6

/* Mensagens de Erro */
%error-verbose

%%
/* REGRAS DA LALG */
programa :
		PROGRAM IDENTIFICADOR pv corpo ponto |
		/* Producoes de erro */
		error { if (reperr) errmsg("'program' esperado."); reperr = 0; } PV corpo ponto 	|
		error { if (reperr) errmsg("'program' esperado."); reperr = 0; } corpo ponto 		|
		PROGRAM error { if (reperr) errmsg("Identificador esperado."); reperr = 0; } pv corpo ponto
		;
corpo :
		dc BEGN comandos END |
		/* Producoes de erro */
		dc BEGN comandos PV error PONTO { if (reperr) errmsg("'end' esperado."); reperr = 0; } |
		dc error { if (reperr) errmsg("'begin' esperado.");  yyclearin; yyerrok; reperr = 0; } comandos END
		;
dc :
		dc_v dc_p
		;
dc_v :
		VAR variaveis dp tipo_var PV dc_v |
		/*lambda*/ |
		/* Producoes de erro */
		VAR variaveis dp error PV { if (reperr) errmsg("Tipo invalido."); yyerrok; reperr = 0; }  dc_v |
		VAR variaveis dp tipo_var error { if (reperr) errmsg("';' faltando depois da declaracao de variavel."); yyerrok; reperr = 0; }  dc_v |
		VAR error { if (reperr) errmsg("Declaracao de variavel invalida."); reperr = 0; }
		;
tipo_var :
		REAL |
		INTEGER |
		error { if (reperr) errmsg("Tipo inválido."); reperr = 0; }
		;
variaveis :
		IDENTIFICADOR mais_var
		;
mais_var :
		VIRG variaveis |
		/*lambda*/
		;
dc_p :
		PROCEDURE IDENTIFICADOR parametros pv corpo_p dc_p |
		/*lambda*/ |
		/* Producoes de erro */
		PROCEDURE IDENTIFICADOR error '\n' { if (reperr) errmsg("Parametros nao reconhecidos."); reperr = 0; } corpo_p dc_p 
		;
parametros :
		a_par lista_par f_par |
		/*lambda*/ |
		/* Producoes de erro */
		A_PAR error F_PAR { if (reperr) errmsg("Parametros nao reconhecidos."); reperr = 0; }
		;
lista_par :
		variaveis dp tipo_var mais_par
		;
mais_par :
		PV lista_par |
		/*lambda*/
		;
corpo_p :
		dc_loc BEGN comandos END pv |
		/* Producoes de erro */
		error BEGN { if (reperr) errmsg("Declaracao local nao reconhecida."); reperr = 0; } comandos END pv |
		dc_loc error { if (reperr) errmsg("'begin' do procedimento esperado."); yyerrok; reperr = 0; } comandos END pv
		;
dc_loc :
		dc_v
		;
lista_arg :
		a_par argumentos f_par |
		/*lambda*/
		;
argumentos :
		IDENTIFICADOR mais_ident
		;
mais_ident :
		PV argumentos |
		/*lambda*/
		;
pfalsa :
		ELSE cmd |
		/*lambda*/
		;
comandos :
		cmd PV comandos |
		/*lambda*/
		;
cmd :
		READ a_par variaveis f_par 		|
		WRITE a_par variaveis f_par		|
		WHILE condicao DO cmd 			|
		REPEAT cmd UNTIL condicao		|
		IF condicao THEN cmd pfalsa 	|
		IDENTIFICADOR id_cont			|
		BEGN comandos END				|
		/* Producoes de erro */
		error { if (reperr) errmsg("Comando não reconhecido."); yyclearin; reperr = 0; } |
		IF condicao error { if (reperr) errmsg("'then' esperado."); yyerrok; reperr = 0; } cmd pfalsa
		;
id_cont :
		RECEBE expressao |
		lista_arg
		;
condicao :
		expressao relacao expressao |
		/* Producoes de erro */
		error { if (reperr) errmsg("Condicao invalida."); reperr = 0; }
		;
relacao :
		IGUAL 	|
		DIF 	|
		MAIORI 	|
		MENORI 	|
		MAIOR	|
		MENOR
		;
expressao :
		termo outros_termos |
		/* Producoes de erro */
		error { if (reperr) errmsg("Expressao invalida."); reperr = 0; }
		;
op_un :
		MAIS |
		MENOS |
		/*lambda*/
		;
outros_termos :
		op_ad termo outros_termos |
		/*lambda*/ |
		/* Producoes de erro */
		op_ad error { if (reperr) errmsg("Operacao invalida."); yyerrok; reperr = 0; }
		;
op_ad :
		MAIS |
		MENOS
		;
termo :
		op_un fator mais_fatores
		;
mais_fatores :
		op_mul fator mais_fatores |
		/*lambda*/
		;
op_mul :
		VZS |
		DIV |
		;
fator : IDENTIFICADOR 	|
		NUMERO_INTEIRO	|
		NUMERO_REAL		|
		A_PAR expressao f_par
		;
/* REGRAS DE TRATAMENTO DE ERROS */
pv :
		PV |
		error { if (reperr) errmsg("';' esperado."); yyerrok; reperr = 0; }
		;
ponto :
		PONTO |
		error { if (reperr) errmsg("'.' esperado."); reperr = 0; }
		;
dp :
		DP |
		error { if (reperr) errmsg("':' esperado."); reperr = 0; }
		;
a_par :
		A_PAR |
		error { if (reperr) errmsg("'(' esperado."); reperr = 0; }
		;
f_par :
		F_PAR |
		error { if (reperr) errmsg("')' esperado."); reperr = 0; }
		;
%%
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

