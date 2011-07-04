#include "Code.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cria um codigo
Code* CodeNew (char* code, int param) {
	Code *c = (Code*) malloc(sizeof(Code));
	c->code = (char*) malloc(sizeof(char) * (strlen(code) + 1));
	strcpy(c->code, code);
	c->param = param;
	c->prox = NULL;
	return c;
}

// deleta um codigo
void CodeDelete (Code* c) {
	if (c != NULL) {
		free(c->code);
		free(c);
	} else {
		fprintf(stderr, "CodeDelete: Desalocando memoria ja desalocada.\n");
	}
}

// inicializa o pcode
void PCodeNew(PCode* p) {
	*p = NULL;
}

// delete o pcode
void PCodeDelete (PCode* p) {
	Code* aux = *p;
	Code* prox;
	while (aux != NULL) {
		prox = aux->prox;
		CodeDelete(aux);
		aux = prox;
	}
	*p = NULL;
}

// insere no comeco
Code* PCodeInsertBegin (PCode *p, char* code, int param) {
	Code* new = CodeNew(code, param);
	
	new->prox = *p;
	*p = new;

	return new;
}

// insere no proximo
Code* PCodeInsertNext (PCode *p, char* code, int param) {
	if (*p == NULL) return NULL;

	Code* new = CodeNew(code, param);
	
	new->prox = (*p)->prox;
	(*p)->prox = new;

	return new;
}

// insere no final 
Code* PCodeInsert (PCode* p, char* code, int param) {
	Code* aux = *p;
	Code* new = CodeNew(code, param);
	
	if (aux == NULL) {
		*p = new;
	} else {
		// vai para o ultimo bloco
		while (aux->prox != NULL) {
			aux = aux->prox;
		}

		aux->prox = new;
	}

	return new;
}

// remove do comeco, retornando o codigo q removeu
Code* PCodeRemove (PCode* p) {
	if (p == NULL) return NULL;

	Code* c = *p;
	*p = c->prox;
	c->prox = NULL;
	
	return c;
}

// numero de linhas de codigo
int PCodeNumLines (PCode* p) {
	int cout = 0;
	Code* aux = *p;
	while (aux != NULL) {
		aux = aux->prox;
		cout++;
	}
	return cout;
}

// salva o pcode
void PCodeSave (PCode* p, char* filename) {
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "PCodeSave: falha ao salvar codigo.");
	} else {
		Code* aux = *p;
		while (aux != NULL) {
			
			fprintf(fp, "%s", aux->code);
			if (aux->param != NO_PARAM) fprintf(fp, " %d", aux->param);
			fprintf(fp, "\n");

			aux = aux->prox;
		}
		fclose(fp);
	}
}

//// teste de unidade
//int main (void) {
//	PCode p;
//	PCodeNew(&p);
//
//	Code *c = PCodeInsert(&p, "INPP", NO_PARAM);
//	PCodeInsert(&p, "PARA", NO_PARAM);
//	
//	PCodeInsertNext(&c, "TESTE", NO_PARAM);
//
//	PCodeSave(&p, "codigo");
//
//	PCodeDelete(&p);
//	return 0;
//}
