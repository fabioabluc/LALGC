#include "StackCode.h"

#include "Code.h"

#include <stdlib.h>

// constructors
StackCode* SCNew () {
	StackCode *si = (StackCode*) malloc (sizeof(StackCode));
	*si = NULL;
	return si;
}

// destructors
void SCDelete (StackCode* si) {
	Code *element = NULL;
	while (!SCEmpty(si)) {
		element = SCPop(si);
	}
	free(si);
	si = NULL;
}

// push
void SCPush (StackCode *si, Code* code) {
	StackCodeElement *aux = (StackCodeElement*) malloc(sizeof(StackCodeElement));
	aux->code = code;
	aux->prox = *si;
	*si = aux;
}

// pop
Code* SCPop (StackCode *si) {
	if (SCEmpty(si)) {
		return NULL;
	} else {
		StackCodeElement *p = *si;
		*si = p->prox;
		Code *c = p->code;
		free(p);
		return c;
	}
}

// checa se a pilha esta vazia
int SCEmpty (StackCode* si) {
	return *si == NULL;
}

// teste de unidade
//#include <stdio.h>
//int main (void) {
//	StackCode *pilha = SCNew();
//	StackCodeElement *aux;
//	
//	SCPush(pilha, 0, 3);
//	SCPush(pilha, 3, 7);
//	SCPush(pilha, 7,10);
//	SCPush(pilha,10,12);
//
//	while (!SCEmpty(pilha)) {
//		aux = SCPop(pilha);
//		printf("(%3d, %3d)\n", aux->start, aux->end);
//		free(aux);
//	}
//	
//	SCDelete(pilha);
//
//	return 0;
//}
