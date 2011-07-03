/* Pre-declaracao de includes e assinaturas de funcoes do lex */
%{
#include <stdio.h>
#include "util/Simble.h"
#include "util/Table.h"
#include "util/StackString.h"
#include "util/Vector.h"

// Numero da linha
int lineno = 1;
// Booleana para erros sintaticos
int synerr = 0;
// Booleana para erros semanticos
int semerr = 0;
// Booleana para reportar erros
int reperr = 0;
// Tabela de simbolos
Table *TS = NULL;
// Lista de variaveis para a regra variaveis
StackString *var_stack = NULL;
Simble *symbol = NULL;
int proc_id = 0;

int yylex (void);
void yywrap(void);
void yyerror(const char *);
void errmsg();

%}

%union {
	char text[50];
	int integer;
	float real;
	int constant;
}

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

%type <text> IDENTIFICADOR
%type <integer> NUMERO_INTEIRO
%type <real> NUMERO_REAL
%type <constant> INTEGER REAL tipo_var id_cont expressao fator op_mul mais_fatores termo outros_termos
/* Supressor de mensagens de shift/reduce */
%expect 7

/* Mensagens de Erro */
%error-verbose

%%
/* REGRAS DA LALG */
programa :
		PROGRAM IDENTIFICADOR pv corpo ponto |
		/* Producoes de erro */
		error { if (reperr) { errmsg(); fprintf(stderr,"'program' esperado.\n"); } reperr = 0; } PV corpo ponto 	|
		error { if (reperr) { errmsg(); fprintf(stderr,"'program' esperado.\n"); } reperr = 0; } corpo ponto 		|
		PROGRAM error { if (reperr) { errmsg(); fprintf(stderr,"Identificador esperado.\n"); } reperr = 0; } pv corpo ponto
		;
corpo :
		dc BEGN comandos END |
		/* Producoes de erro */
		dc BEGN comandos PV error PONTO { if (reperr) { errmsg(); fprintf(stderr,"'end' esperado.\n"); } reperr = 0; } |
		dc error { if (reperr) { errmsg(); fprintf(stderr,"'begin' esperado.\n"); }  yyclearin; yyerrok; reperr = 0; } comandos END
		;
dc :
		dc_v dc_p { proc_id = 0; } 
		;
dc_v :
		VAR variaveis dp tipo_var {
			// Adiciona na tabela
			while (SSSize(var_stack) > 0) {
				char *var_name = SSPop(var_stack);
				int indice = TableSearchNCS(TS,var_name,CLASSE_VAR,proc_id);
				if (indice != -1) {
					Simble *var = TS->simbolos[indice];
					if (var->argument == ARGUMENT_FALSE) {
						// Identificador ja declarado
						semerr = 1;
						errmsg(); fprintf(stderr,"Identificador '%s' duplicado.\n", var_name);
					} else {
						Simble *var = SimbleNew();
						SimbleSetName(var,var_name);
						var->classe = CLASSE_VAR;
						var->type = $4; // $4 = tipo_var.tipo
						var->value = 0;
						var->argument = ARGUMENT_FALSE;
						var->from_proc = proc_id;
						TableAdd(TS,var);
					}
				} else {
					Simble *var = SimbleNew();
					SimbleSetName(var,var_name);
					var->classe = CLASSE_VAR;
					var->type = $4; // $4 = tipo_var.tipo
					var->value = 0;
					var->argument = ARGUMENT_FALSE;
					var->from_proc = proc_id;
					TableAdd(TS,var);
				}
			}
			var_stack = NULL;
		}
		PV dc_v |
		/*lambda*/ |
		/* Producoes de erro */
		VAR variaveis dp error PV { if (reperr) { errmsg(); fprintf(stderr,"Tipo invalido.\n"); } yyerrok; reperr = 0; }  dc_v |
		VAR variaveis dp tipo_var error { if (reperr) { errmsg(); fprintf(stderr,"';' faltando depois da declaracao de variavel.\n"); } yyerrok; reperr = 0; }  dc_v |
		VAR error { if (reperr) { errmsg(); fprintf(stderr,"Declaracao de variavel invalida.\n"); } reperr = 0; }
		;
tipo_var :
		REAL { $$ = TYPE_REAL; } |
		INTEGER { $$ = TYPE_INTEGER; } |
		error { if (reperr) { errmsg(); fprintf(stderr,"Tipo inválido.\n"); } reperr = 0; }
		;
variaveis :
		IDENTIFICADOR mais_var {
			if (var_stack == NULL) var_stack = SSNew();
			SSPush(var_stack,$1);
		}
		;
mais_var :
		VIRG variaveis |
		/*lambda*/
		;
dc_p :
		PROCEDURE IDENTIFICADOR {
			// Procura na tabela de simbolos
			int indice = TableSearch(TS,$2);
			if (indice != -1) {
				Simble *proc = TS->simbolos[indice];
				if (proc->classe != CLASSE_PRC) {
					// Adiciona na tabela
					Simble *proc = SimbleNew();
					SimbleSetName(proc,yylval.text);
					proc->classe = CLASSE_PRC;
					proc->type = proc_id+1;
					proc->argument = ARGUMENT_FALSE;
					proc->from_proc = 0;
					TableAdd(TS,proc);
				} else {
					// Identificador ja declarado
					semerr = 1;
					errmsg(); fprintf(stderr,"Identificador '%s' duplicado.\n",$2);
					reperr = 1;
				}
			} else {
				// Adiciona na tabela
				Simble *proc = SimbleNew();
				SimbleSetName(proc,yylval.text);
				proc->classe = CLASSE_PRC;
				proc->type = proc_id+1;
				proc->argument = ARGUMENT_FALSE;
				proc->from_proc = 0;
				TableAdd(TS,proc);
			}
			++proc_id;
		}
		parametros {
			if (!reperr) {
				int indice = TableSearch(TS,$2);
				Simble *proc = TS->simbolos[indice];
				proc->number = TableSearchParams(TS,proc_id)->size;
			}
			reperr = 0;
		}
		pv corpo_p dc_p |
		/*lambda*/ |
		/* Producoes de erro */
		PROCEDURE IDENTIFICADOR error '\n' { if (reperr) { errmsg(); fprintf(stderr,"Parametros nao reconhecidos.\n"); } reperr = 0; } corpo_p dc_p 
		;
parametros :
		a_par lista_par f_par |
		/*lambda*/ |
		/* Producoes de erro */
		A_PAR error F_PAR { if (reperr) { errmsg(); fprintf(stderr,"Parametros nao reconhecidos.\n"); } reperr = 0; }
		;
lista_par :
		variaveis dp tipo_var {
			// Adiciona na tabela
			while (SSSize(var_stack) > 0) {
				char *var_name = SSPop(var_stack);
				int indice = TableSearchFromProc(TS,var_name,proc_id);
				if (indice != -1) {
					Simble *param = TS->simbolos[indice];
					if (param->argument == ARGUMENT_TRUE) {
						// Parametro ja declarado
						semerr = 1;
						errmsg(); fprintf(stderr,"Parâmetro '%s' duplicado.\n",var_name);
					} else {
						Simble *param = SimbleNew();
						SimbleSetName(param,var_name);
						param->classe = CLASSE_VAR;
						param->type = $3; // $3 = tipo_var.tipo
						param->argument = ARGUMENT_TRUE;
						param->from_proc = proc_id;
						TableAdd(TS,param);
					}
				} else {
					Simble *param = SimbleNew();
					SimbleSetName(param,var_name);
					param->classe = CLASSE_VAR;
					param->type = $3; // $3 = tipo_var.tipo
					param->argument = ARGUMENT_TRUE;
					param->from_proc = proc_id;
					TableAdd(TS,param);
				}
			}
			var_stack = NULL;
		}
		mais_par
		;
mais_par :
		PV lista_par |
		/*lambda*/
		;
corpo_p :
		dc_loc BEGN comandos END pv |
		/* Producoes de erro */
		error BEGN { if (reperr) { errmsg(); fprintf(stderr,"Declaracao local nao reconhecida.\n"); } reperr = 0; } comandos END pv |
		dc_loc error { if (reperr) { errmsg(); fprintf(stderr,"'begin' do procedimento esperado.\n"); } yyerrok; reperr = 0; } comandos END pv
		;
dc_loc :
		dc_v
		;
lista_arg :
		a_par argumentos f_par |
		/*lambda*/
		;
argumentos :
		IDENTIFICADOR mais_ident {
			if (var_stack == NULL) var_stack = SSNew();
			SSPush(var_stack,$1);
		}
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
		READ a_par variaveis f_par {
			int var_type = -1;
			while (!SSEmpty(var_stack)) {
				char *var_name = SSPop(var_stack);
				int indice = TableSearchNCS(TS,var_name,CLASSE_VAR,proc_id);
				if (indice != -1) {
					Simble *var = TS->simbolos[indice];
					if (var_type == -1) var_type = var->type;
					else if (var_type != var->type) {
						semerr = 1;
						errmsg(); fprintf(stderr,"READ com variáveis de tipos diferentes.\n");
						break;
					}
				} else {
					semerr = 1;
					errmsg(); fprintf(stderr,"Variável '%s' não declarada.\n",var_name);
				}
			}
		} |
		WRITE a_par variaveis f_par	{
			int var_type = -1;
			while (!SSEmpty(var_stack)) {
				char *var_name = SSPop(var_stack);
				int indice = TableSearchNCS(TS,var_name,CLASSE_VAR,proc_id);
				if (indice != -1) {
					Simble *var = TS->simbolos[indice];
					if (var_type == -1) var_type = var->type;
					else if (var_type != var->type) {
						semerr = 1;
						errmsg(); fprintf(stderr,"WRITE com variáveis de tipos diferentes.\n");
						break;
					}
				} else {
					semerr = 1;
					errmsg(); fprintf(stderr,"Variável '%s' não declarada.\n",var_name);
				}
			}
		} |
		WHILE condicao DO cmd 			|
		REPEAT cmd UNTIL condicao		|
		IF condicao THEN cmd pfalsa 	|
		IDENTIFICADOR {
			//Verificando declaracao
			int indice = TableSearchFromProc(TS,$1,proc_id);
			if (indice == -1) {
				// Identificador não encontrado
				semerr = 1;
				errmsg(); fprintf(stderr,"Identificador '%s' não encontrado.\n",$1);
			} else {
				symbol = TS->simbolos[indice];
			}
		} 
		id_cont {
			int indice = TableSearchFromProc(TS,$1,proc_id);
			if (indice == -1) {
				// Identificador não encontrado
				semerr = 1;
				errmsg(); fprintf(stderr,"Identificador '%s' não encontrado.\n",$1);				
			}
		} |
		BEGN comandos END				|
		/* Producoes de erro */
		error { if (reperr) { errmsg(); fprintf(stderr,"Comando não reconhecido.\n"); yyclearin; } reperr = 0; } |
		IF condicao error { if (reperr) { errmsg(); fprintf(stderr,"'then' esperado.\n"); } yyerrok; reperr = 0; } cmd pfalsa
		;
id_cont :
		RECEBE expressao {	
			if (symbol != NULL && symbol->classe != CLASSE_VAR) {
				semerr = 1;
				errmsg(); fprintf(stderr,"Identificador '%s' não é uma variável.\n",symbol->name);
			} else if (symbol != NULL && symbol->type != TYPE_REAL && $2 == TYPE_REAL) {
				semerr = 1;
				errmsg(); fprintf(stderr,"Atribuicao de tipos incompatíveis.\n");
			}
			symbol = NULL;
		} |
		lista_arg {
			if (symbol != NULL) {
				int indice = TableSearchNCS(TS,symbol->name,CLASSE_PRC,proc_id);
				if (indice != -1) {
					Simble *proc = TS->simbolos[indice];
					if (proc->number == SSSize(var_stack)) {
						Vector *formal = TableSearchParams(TS,proc->type);
						int i;
						for (i = 0; i < formal->size; i++) {
							char *real_name = SSPop(var_stack);
							indice = TableSearchNCS(TS,real_name,CLASSE_VAR,proc_id);
							if (indice != -1) {
								Simble *real = TS->simbolos[indice];
								Simble *form = TS->simbolos[formal->simbolos[i]];
								if (real->type != form->type) {
									semerr = 1;
									errmsg(); fprintf(stderr,"Parâmetro %d do procedimento '%s'. Tipo de '%s' incompatível.\n",i+1,proc->name,real->name);
								}
							} else {
								semerr = 1;
								//Parametro real invalido
								errmsg(); fprintf(stderr,"Parâmetro '%s' não encontrado.\n",real_name);
							}
						}
					} else {
						semerr = 1;
						errmsg(); fprintf(stderr,"Número de parâmetros de '%s' inválido.\n",proc->name);
					}
				} else {
					semerr = 1;
					errmsg(); fprintf(stderr,"Procedimento '%s' não declarado.\n",symbol->name);
				}
			}
			symbol = NULL;
		}
		;
condicao :
		expressao relacao expressao |
		/* Producoes de erro */
		error { if (reperr) { errmsg(); fprintf(stderr,"Condicao invalida.\n"); } reperr = 0; }
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
		termo outros_termos {
			if ($1 == TYPE_REAL || $2 == TYPE_REAL) $$ = TYPE_REAL;
			else $$ = TYPE_INTEGER;
		} |
		/* Producoes de erro */
		error { if (reperr) { errmsg(); fprintf(stderr,"Expressao invalida.\n"); } reperr = 0; }
		;
op_un :
		MAIS |
		MENOS |
		/*lambda*/
		;
outros_termos :
		op_ad termo outros_termos {
			if ($2 == TYPE_REAL || $3 == TYPE_REAL) $$ = TYPE_REAL;
			else $$ = TYPE_INTEGER;
		} |
		/*lambda*/ |
		/* Producoes de erro */
		op_ad error { if (reperr) { errmsg(); fprintf(stderr,"Operacao invalida.\n"); } yyerrok; reperr = 0; }
		;
op_ad :
		MAIS |
		MENOS
		;
termo :
		op_un fator mais_fatores {
			if ($2 == TYPE_REAL || $3 == TYPE_REAL) $$ = TYPE_REAL;
			else $$ = TYPE_INTEGER;
		}
		;
mais_fatores :
		op_mul fator mais_fatores {
			if ($1 == DIV && $2 == TYPE_REAL) {
				semerr = 1;
				errmsg(); fprintf(stderr,"Divisão por número real.\n");
			}
			$$ = $2;
		} |
		/*lambda*/
		;
op_mul :
		VZS { $$ = VZS; } |
		DIV { $$ = DIV; } |
		;
fator : IDENTIFICADOR {
			//Verificando declaracao
			int indice = TableSearchNCS(TS,$1,CLASSE_VAR,proc_id);
			if (indice == -1) {
				// Identificador não encontrado
				semerr = 1;
				errmsg(); fprintf(stderr,"Identificador '%s' não encontrado.\n", $1);
				$$ = -1;
			} else {
				Simble *simbolo = TS->simbolos[indice];
				$$ = simbolo->type;
			}
		} |
		NUMERO_INTEIRO { $$ = TYPE_INTEGER; } |
		NUMERO_REAL	{ $$ = TYPE_REAL; } |
		A_PAR expressao f_par { $$ = $2; }
		;
/* REGRAS DE TRATAMENTO DE ERROS */
pv :
		PV |
		error { if (reperr) { errmsg(); fprintf(stderr,"';' esperado.\n"); } yyerrok; reperr = 0; }
		;
ponto :
		PONTO |
		error { if (reperr) { errmsg(); fprintf(stderr,"'.' esperado.\n"); } reperr = 0; }
		;
dp :
		DP |
		error { if (reperr) { errmsg(); fprintf(stderr,"':' esperado.\n"); } reperr = 0; }
		;
a_par :
		A_PAR |
		error { if (reperr) { errmsg(); fprintf(stderr,"'(' esperado.\n"); } reperr = 0; }
		;
f_par :
		F_PAR |
		error { if (reperr) { errmsg(); fprintf(stderr,"')' esperado.\n"); } reperr = 0; }
		;
%%
// Chamada quando encontra um fim de arquivo
void yywrap(void) {
	fflush(stderr);
	fprintf(stdout, "FIM DA ANALISE\n"); fflush(stdout);
	if (synerr || semerr) {
		if (synerr) fprintf(stdout,"Erro sintático encontrado.\n");
		if (semerr) fprintf(stdout,"Erro semântico encontrado.\n");
	} else {
		fprintf(stdout,"Compilacao concluida com sucesso.\n");
	}
	
	// Print Tabela de simbolos
	int i;
	for (i = 0; i < TS->size; i++) {
		printf("%d: %s\n",i,SimbleToString(TableGet(TS,i)));
	}
}
// Chamada quando encontra um erro
void yyerror(const char *s) {
	synerr = 1;
	reperr = 1;
	//fprintf(stderr, "YYError:%d: %s\n", lineno, s);
}
void errmsg() {
	fprintf(stderr, "Erro:%d: ", lineno);
}

