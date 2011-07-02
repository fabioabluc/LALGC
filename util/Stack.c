#include "Stack.h"

#include <stdlib.h>

// constructors
StackInterval* SINew () {
	StackInterval *si = (StackInterval*) malloc (sizeof(StackInterval));
	*si = NULL;
	return si;
}

// destructors
void SIDelete (StackInterval* si) {
	StackIntervalElement *element = NULL;
	while (!SIEmpty(si)) {
		element = SIPop(si);
		free(element);
	}
	free(si);
	si = NULL;
}

// push
void SIPush (StackInterval *si, int start, int end) {
	StackIntervalElement *aux = (StackIntervalElement*) malloc(sizeof(StackIntervalElement));
	aux->start = start;
	aux->end = end;
	aux->prox = *si;
	*si = aux;
}

// pop
StackIntervalElement* SIPop (StackInterval *si) {
	if (SIEmpty(si)) {
		return NULL;
	} else {
		StackIntervalElement *p = *si;
		*si = p->prox;
		return p;
	}
}

// checa se a pilha esta vazia
int SIEmpty (StackInterval* si) {
	return *si == NULL;
}

// teste de unidade
//#include <stdio.h>
//int main (void) {
//	StackInterval *pilha = SINew();
//	StackIntervalElement *aux;
//	
//	SIPush(pilha, 0, 3);
//	SIPush(pilha, 3, 7);
//	SIPush(pilha, 7,10);
//	SIPush(pilha,10,12);
//
//	while (!SIEmpty(pilha)) {
//		aux = SIPop(pilha);
//		printf("(%3d, %3d)\n", aux->start, aux->end);
//		free(aux);
//	}
//	
//	SIDelete(pilha);
//
//	return 0;
//}
