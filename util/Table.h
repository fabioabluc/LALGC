#ifndef _TABLE_H_
#define _TABLE_H_

#include "Simble.h"

#include "Vector.h"

typedef struct {
	Simble** simbolos;
	int size;
} Table;

// constructors
Table* TableNew ();

// destructors
void TableDelete (Table *v);

// add
void TableAdd (Table *v, Simble* s);

// get
int TableSize (Table *v);
Simble* TableGet  (Table *v, int index);

// remove
void TableRemove (Table *v, int index);

// ordena o vetor
void TableSort (Table *v);

// ordena o vetor, dado um intervalo
void TableSortInterval (Table *v, int begin, int end);

// busca
// retorna o indice
int TableSearch (Table *v, char *name);

// busca por nome e from_proc
int TableSearchFromProc (Table *v, char *name, int from_proc);

// busca por nome e contexto
int TableSearchFromContext (Table *v, char *name, int from_proc);

int TableSearchNCS (Table *v, char *name, int classe, int scope);

Vector* TableSearchParams (Table *v, int from_proc);

// conta quantidade de variaveis locais
int TableCountLocal (Table *v, int from_proc);

#endif
