#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>

// pilha de intervalos
typedef struct _StackIntervalElement {
	int start;
	int end;
	struct _StackIntervalElement *prox;
} StackIntervalElement;
typedef StackIntervalElement* StackInterval;

// constructors
StackInterval* SINew ();

// destructors
void SIDelete (StackInterval* si);

// push
void SIPush (StackInterval *si, int start, int end);

// pop
StackIntervalElement* SIPop (StackInterval *si);

// checa se a pilha esta vazia
int SIEmpty (StackInterval* si);

#endif
