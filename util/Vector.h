#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef struct {
	long* simbolos;
	long size;
} Vector;

// constructors
Vector* VectorNew ();

// destructors
void VectorDelete (Vector *v);

// add
void VectorAdd (Vector *v, long numero);

// get
long VectorSize (Vector *v);
long VectorGet  (Vector *v, long index);

// remove
void VectorRemove (Vector *v, long index);


// ordena o vetor
void VectorSort (Vector *v);

// ordena o vetor, dado um intervalo
void VectorSortInterval (Vector *v, long begin, long end);

// busca
// retorna o indice
long VectorSearch (Vector *v, long number);

// junta dois vetores utilizando o merge sort
Vector* VectorMerge (Vector *v1, Vector *v2);

#endif
