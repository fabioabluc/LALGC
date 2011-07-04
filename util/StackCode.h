#ifndef _STACKCODE_H_
#define _STACKCODE_H_

#include "Code.h"

#include <stdlib.h>

// pilha de intervalos
typedef struct _StackCodeElement {
	Code* code;
	struct _StackCodeElement *prox;
} StackCodeElement;
typedef StackCodeElement* StackCode;

// constructors
StackCode* SCNew ();

// destructors
void SCDelete (StackCode* si);

// push
void SCPush (StackCode *si, Code* code);

// pop
Code* SCPop (StackCode *si);

// checa se a pilha esta vazia
int SCEmpty (StackCode* si);

#endif
