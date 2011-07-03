#include "Vector.h"

#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>

// constructors
Vector* VectorNew () {
	Vector *v = (Vector*) malloc (sizeof(Vector));
	v->simbolos = NULL;
	v->size = 0;
	return v;
}

// destructors
void VectorDelete (Vector *v) {
	if (v != NULL) {
		free(v->simbolos);
		free(v);
		v = NULL;
	}
}

// add
void VectorAdd (Vector *v, long numero) {
	v->size++;
	v->simbolos = (long*) realloc (v->simbolos, sizeof(long) * v->size);
	v->simbolos[v->size - 1] = numero;
}

// get
long VectorSize (Vector *v) { return v->size; }
long VectorGet  (Vector *v, long index) {
	if (index >= 0 && index < v->size)
		return v->simbolos[index];
	else
		return 0;
}

// remove
void VectorRemove (Vector *v, long index) {
	if (index >= 0 && index < v->size) {
		v->size--;
		v->simbolos[index] = v->simbolos[v->size];
		v->simbolos = (long*) realloc (v->simbolos, sizeof(long) * v->size);
	}
}

// ordena o vetor
void VectorSort (Vector *v) { VectorSortInterval(v, 0, v->size - 1); }
void VectorSortInterval (Vector *v, long begin, long end) {
	StackInterval *pilha = SINew();
	StackIntervalElement *elem;

	SIPush(pilha, begin, end);
	
	while (!SIEmpty(pilha)) {
		elem = SIPop(pilha);

		long p = elem->start;
		long r = elem->end;
		free(elem); elem = NULL;

		if (p < r) {
			long vpivo = p; // sempre do comeco
			long pivo = v->simbolos[vpivo];
			v->simbolos[vpivo] = v->simbolos[r];
			v->simbolos[r] = pivo;

			long i = p - 1;
			long j = r;

			do {
				do { i++; } while (v->simbolos[i] < pivo);
				do { j--; } while (v->simbolos[j] > pivo && j > p);

				if (i < j) {
					long aux = v->simbolos[i];
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

// junta dois vetores utilizando o merge sort
Vector* VectorMerge (Vector *v1, Vector *v2) {
	long pos1 = 0;
	long pos2 = 0;

	Vector *v = VectorNew();

	while (pos1 < v1->size || pos2 < v2->size) {
		if (pos1 < v1->size && pos2 < v2->size) {
			if (v1->simbolos[pos1] <= v2->simbolos[pos2]) {
				VectorAdd(v, v1->simbolos[pos1]);
				pos1++;
			} else {
				VectorAdd(v, v2->simbolos[pos2]);
				pos2++;
			}
		} else if (pos1 < v1->size) {
			VectorAdd(v, v1->simbolos[pos1]);
			pos1++;
		} else if (pos2 < v2->size) {
			VectorAdd(v, v2->simbolos[pos2]);
			pos2++;
		}
	}

	return v;
}

// busca
// retorna o indice
long VectorSearch (Vector *v, long number) {
	long inf = 0;
	long sup = v->size - 1;
	long meio;
	long achou = 0;
	long compara;
	
	while (!achou && (inf <= sup)) {
		meio = (inf + sup) / 2;
		compara = v->simbolos[meio] - number;
		if (compara == 0) {
			achou = 1;
		} else if (compara > 0) {
			sup = meio - 1;
		} else if (compara < 0) {
			inf = meio + 1;
		}
	}
	if (achou) return v->simbolos[meio]; 
	else return -1;
}
