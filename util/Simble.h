#ifndef _SIMBLE_H_
#define _SIMBLE_H_

// classes
#define CLASSE_VAR 0  // variavel
#define CLASSE_PRC 1  // procedimento
#define CLASSE_NME 2  // nome do programa

// type
#define TYPE_INTEGER 0 // inteiro
#define TYPE_REAL    1 // real

// argumento
#define ARGUMENT_FALSE 0 // NAO eh um argumento
#define ARGUMENT_TRUE  1 // eh um argumento

typedef struct {
	char  name[30]; // nome do simbolo
	int   classe;   // variavel / procedimento / nome do programa
	int   type;     // integer / real
	float value;    // valor da variavel

	// para procedimentos
	int  number;    // numero de parametros
	int  argument;  // eh um argumento?
	int  from_proc; // de qual procedimento esta variavel pertence

	// para geracao de codigo
	int  position;  // posicao da stack q se encontra esta variavel
} Simble;

// novo simbolo
Simble *SimbleNew();

// deleta o simbolo
void SimbleDelete(Simble* s);

// define o nome do simbolo
void SimbleSetName(Simble *s, char* newName);

// converte o simbolo para uma string
char* SimbleToString (Simble*s);

#endif
