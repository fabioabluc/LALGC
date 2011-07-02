#include "Table.h"

#include "Simble.h"
#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constructors
Table* TableNew () {
	Table *v = (Table*) malloc (sizeof(Table));
	v->simbolos = NULL;
	v->size = 0;
	return v;
}

// destructors
void TableDelete (Table *v) {
	if (v != NULL) {
		int i;
		for (i = 0; i < v->size; i++)
			SimbleDelete(v->simbolos[i]);
		free(v->simbolos);
		free(v);
		v = NULL;
	}
}

// add
void TableAdd (Table *v, Simble* s) {
	v->size++;
	v->simbolos = (Simble**) realloc (v->simbolos, sizeof(Simble*) * v->size);
	v->simbolos[v->size - 1] = s;
}

// get
int TableSize (Table *v) { return v->size; }
Simble* TableGet  (Table *v, int index) {
	if (index >= 0 && index < v->size)
		return v->simbolos[index];
	else
		return 0;
}

// remove
void TableRemove (Table *v, int index) {
	if (index >= 0 && index < v->size) {
		v->size--;
		SimbleDelete(v->simbolos[index]);
		v->simbolos[index] = v->simbolos[v->size];
		v->simbolos = (Simble**) realloc (v->simbolos, sizeof(Simble*) * v->size);
	}
}

// ordena o vetor
void TableSort (Table *v) { TableSortInterval(v, 0, v->size - 1); }
void TableSortInterval (Table *v, int begin, int end) {
	StackInterval *pilha = SINew();
	StackIntervalElement *elem;

	SIPush(pilha, begin, end);
	
	while (!SIEmpty(pilha)) {
		elem = SIPop(pilha);

		int p = elem->start;
		int r = elem->end;
		free(elem); elem = NULL;

		if (p < r) {
			int vpivo = p; // sempre do comeco
			Simble* pivo = v->simbolos[vpivo];
			v->simbolos[vpivo] = v->simbolos[r];
			v->simbolos[r] = pivo;

			int i = p - 1;
			int j = r;

			do {
				do { i++; } while (strcmp(v->simbolos[i]->name, pivo->name) < 0);
				do { j--; } while (strcmp(v->simbolos[j]->name, pivo->name) > 0 && j > p);

				if (i < j) {
					Simble* aux = v->simbolos[i];
					v->simbolos[i] = v->simbolos[j];
					v->simbolos[j] = aux;
				}
			} while (i < j);

			v->simbolos[r] = v->simbolos[i];
			v->simbolos[i] = pivo;

			SIPush (pilha, p, i - 1);
			SIPush (pilha, i + 1, r);
		}
	}

	SIDelete(pilha);
}

// busca
// retorna o indice
int TableSearch (Table *v, char *name) {
	int inf = 0;
	int sup = v->size - 1;
	int meio;
	int achou = 0;
	int compara;
	
	while (!achou && (inf <= sup)) {
		meio = (inf + sup) / 2;
		compara = strcmp(v->simbolos[meio]->name, name);
		if (compara == 0) {
			achou = 1;
		} else if (compara > 0) {
			sup = meio - 1;
		} else if (compara < 0) {
			inf = meio + 1;
		}
	}
	if (achou) return meio; 
	else return -1;
}

// teste de unidade
int main (void) {
	Table *t = TableNew();
	
	Simble *s = NULL;

	s = SimbleNew();
	SimbleSetName(s, "x");
	s->classe = CLASSE_VAR;
	s->type = TYPE_INTEGER;
	s->value = 10;
	TableAdd(t, s);
	
	s = SimbleNew();
	SimbleSetName(s, "proc");
	s->classe = CLASSE_PRC;
	s->number = 1;
	TableAdd(t, s);
	
	s = SimbleNew();
	SimbleSetName(s, "y");
	s->classe = CLASSE_VAR;
	s->type = TYPE_INTEGER;
	s->value = 0;
	s->argument = ARGUMENT_TRUE;
	s->from_proc = 1;
	TableAdd(t, s);
	
	int i;
	for (i = 0; i < TableSize(t); i++)
		printf("%s\n", SimbleToString(TableGet(t, i)));

	TableDelete(t);

	return 0;
}
