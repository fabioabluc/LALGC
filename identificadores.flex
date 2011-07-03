%{

/* includes necessarios */
#include "sintatico.tab.h"
#include <stdlib.h>
#include "util/Simble.h"
#include "util/Table.h"

/* numero da linha atual a sendo testada 
*  util para informacoes de erro 
*/
extern int lineno;
// Tabelas de Simbolos
extern Table *TS;

int classify_identifier(char *token);
%}

/*%option noyywrap*/

LETRA                [a-zA-Z_]
NUMERO               [0-9]
LETRANUMERO          {LETRA}|{NUMERO}
NUM_INTEIRO          {NUMERO}+
NUM_REAL             {NUMERO}+\.{NUMERO}+
IDENT                {LETRA}{LETRANUMERO}*
NUM_INT_ERRO         {NUMERO}+({LETRA}+{NUMERO}*)+
NUM_REAL_ERRO        {NUMERO}+({LETRA}*{NUMERO}*)+\.(\.|{NUM_INT_ERRO}|{NUM_INTEIRO})+

%%
{IDENT}              { strcpy(yylval.text,yytext); return classify_identifier(yytext); }
{NUM_INTEIRO}        { yylval.integer = atoi(yytext); return NUMERO_INTEIRO; }
{NUM_REAL}           { yylval.real = atof(yytext); return NUMERO_REAL; }

"("                  { return classify_identifier(yytext); }
")"                  { return classify_identifier(yytext); }
"*"                  { return classify_identifier(yytext); }
"+"                  { return classify_identifier(yytext); }
","                  { return classify_identifier(yytext); }
"-"                  { return classify_identifier(yytext); }
"."                  { return classify_identifier(yytext); }
"/"                  { return classify_identifier(yytext); }
":="                 { return classify_identifier(yytext); }
":"                  { return classify_identifier(yytext); }
";"                  { return classify_identifier(yytext); }
"<>"                 { return classify_identifier(yytext); }
"<="                 { return classify_identifier(yytext); }
"<"                  { return classify_identifier(yytext); }
"="                  { return classify_identifier(yytext); }
">="                 { return classify_identifier(yytext); }
">"                  { return classify_identifier(yytext); }
 
\n                   { lineno++; }

"{"[^}\n]*"}"
[ \t]+

{NUM_INT_ERRO}       { fprintf(stderr, "Warning:%d: Identificador '%s' invalido.\n", lineno, yytext); return IDENTIFICADOR_NAO_ENCONTRADO; }
{NUM_REAL_ERRO}      { fprintf(stderr, "Warning:%d: Identificador '%s' invalido.\n", lineno, yytext); return IDENTIFICADOR_NAO_ENCONTRADO; }
.                    { fprintf(stderr, "Warning:%d: Identificador '%s' invalido.\n", lineno, yytext); return IDENTIFICADOR_NAO_ENCONTRADO; }

%%
int get_token (char **token) {
	int retorno = yylex();
	
	*token = (char*) realloc (*token, sizeof(char) * ( yyleng + 1));
	strcpy(*token, yytext);

	return retorno;
}

int h (char *token) {
    int i = 0, key = 0;

    // Soma ateh os quatro primeiros ASCII com ponderacao
    while ((token[i] != '\0')&&(i < 4)) {
        key += token[i]*4^(i+1); 
        i++;
    }
    return key%70;
}

char** hash () {
	char **reservadas;
	int n = 68;
	int i;
	
	reservadas = (char**) malloc(n * sizeof(char*));
	for (i = 0; i < n; i++)
   		reservadas[i] = NULL;
	
	reservadas[20] = "begin";
	reservadas[ 7] = "do";
	reservadas[22] = "else";
	reservadas[60] = "end";
	reservadas[61] = "if";
	reservadas[50] = "integer";
	reservadas[66] = "procedure";
	reservadas[12] = "program";
	reservadas[48] = "read";
	reservadas[10] = "real";
	reservadas[34] = "repeat";
	reservadas[54] = "then";
	reservadas[44] = "until";
	reservadas[62] = "var";
	reservadas[ 4] = "while";
	reservadas[ 6] = "write";
	reservadas[21] = "(";
	reservadas[25] = ")";
	reservadas[29] = "*";
	reservadas[33] = "+";
	reservadas[37] = ",";
	reservadas[41] = "-";
	reservadas[45] = ".";
	reservadas[49] = "/";
	reservadas[59] = ":=";
	reservadas[23] = ":";
	reservadas[27] = ";";
	reservadas[ 1] = "<>";
	reservadas[67] = "<=";
	reservadas[31] = "<";
	reservadas[35] = "=";
	reservadas[ 5] = ">=";
	reservadas[39] = ">";
	
	return reservadas;
}

int* types() {
	int *tipos;
	int n = 68;
	int i;
	
	tipos = (int*) malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
   		tipos[i] = -1;
	
	tipos[20] = BEGN;
	tipos[ 7] = DO;
	tipos[22] = ELSE;
	tipos[60] = END;
	tipos[61] = IF;
	tipos[50] = INTEGER;
	tipos[66] = PROCEDURE;
	tipos[12] = PROGRAM;
	tipos[48] = READ;
	tipos[10] = REAL;
	tipos[34] = REPEAT;
	tipos[54] = THEN;
	tipos[44] = UNTIL;
	tipos[62] = VAR;
	tipos[ 4] = WHILE;
	tipos[ 6] = WRITE;
	tipos[21] = A_PAR;
	tipos[25] = F_PAR;
	tipos[29] = VZS;
	tipos[33] = MAIS;
	tipos[37] = VIRG;
	tipos[41] = MENOS;
	tipos[45] = PONTO;
	tipos[49] = DIV;
	tipos[59] = RECEBE;
	tipos[23] = DP;
	tipos[27] = PV;
	tipos[ 1] = DIF;
	tipos[67] = MENORI;
	tipos[31] = MENOR;
	tipos[35] = IGUAL;
	tipos[ 5] = MAIORI;
	tipos[39] = MAIOR;
	
	return tipos;
}

int get_token_type (char *token, char **hashtable, int *typetable) {
	int retorno = IDENTIFICADOR;
	int hashindex;
	
    if (hashtable[h(token)] != NULL) {
    	hashindex = h(token);
		if (strcmp(hashtable[hashindex], token) == 0) {
			retorno = typetable[hashindex];
		}
    }
    
	return retorno;
}

int classify_identifier(char *token) {
	// povoa a tabela hash
	char **palavras_reservadas = hash();
	// aloca o vetor de tipos dos tokens
	int *tipos_tokens = types();
	
	return get_token_type(token,palavras_reservadas,tipos_tokens);
}

int main(int argc, char **argv) {
	++argv, --argc;  /* skip over program name */
	
	// verifica se vai ler do teclado ou de um arquivo
	if ( argc > 0 )
			yyin = fopen( argv[0], "r" );
	else
			yyin = stdin;
	
	TS = TableNew();
	yyparse();
	fclose(yyin);

	return 0;
}

