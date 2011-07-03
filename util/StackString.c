#include "StackString.h"

#include <string.h>
#include <stdlib.h>

// constructors
StackString* SSNew () {
	StackString *si = (StackString*) malloc (sizeof(StackString));
	*si = NULL;
	return si;
}

// destructors
void SSDelete (StackString* si) {
	while (!SSEmpty(si)) {
		SSPop(si);
	}
	free(si);
	si = NULL;
}

// push
void SSPush (StackString *si, char *string) {
	StackStringElement *aux = (StackStringElement*) malloc(sizeof(StackStringElement));
	aux->string = (char*) malloc (sizeof(char)*(strlen(string) + 1));
	strcpy(aux->string, string);
	aux->prox = *si;
	*si = aux;
}

// pop
char* SSPop (StackString *si) {
	if (SSEmpty(si)) {
		return NULL;
	} else {
		StackStringElement *p = *si;
		*si = p->prox;
		char* str = p->string;
		free(p);
		return str;
	}
}

// checa se a pilha esta vazia
int SSEmpty (StackString* si) {
	return *si == NULL;
}

// tamanho da pilha
int SSSize (StackString* si) {
	StackStringElement *aux = *si;
	int count = 0;
	while (aux != NULL) {
		count++;
		aux = aux->prox;
	}
	return count;
}

//// teste de unidade
//#include <stdio.h>
//int main (void) {
//	StackString *pilha = SSNew();
//	char *aux;
//	
//	SSPush(pilha, "a");
//	SSPush(pilha, "b");
//	SSPush(pilha, "c");
//	SSPush(pilha, "d");
//	
//	printf("%d\n", SSSize(pilha));
//	while (!SSEmpty(pilha)) {
//		aux = SSPop(pilha);
//		printf("%s\n", aux);
//		free(aux);
//	}
//	
//	SSDelete(pilha);
//
//	return 0;
//}
