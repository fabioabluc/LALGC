#ifndef _STACK_S_H_
#define _STACK_S_H_

#include <stdlib.h>

// pilha de intervalos
typedef struct _StackStringElement {
	char *string;
	struct _StackStringElement *prox;
} StackStringElement;
typedef StackStringElement* StackString;

// constructors
StackString* SSNew ();

// destructors
void SSDelete (StackString* si);

// push
void SSPush (StackString *si, char *string);

// pop
char* SSPop (StackString *si);

// checa se a pilha esta vazia
int SSEmpty (StackString* si);

// tamanho da pilha
int SSSize (StackString* si);

#endif
