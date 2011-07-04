#ifndef _CODE_H_
#define _CODE_H_

#define NO_PARAM -1

typedef struct _Code {
	char* code;
	int param;
	struct _Code* prox;
} Code;
typedef Code* PCode;

// cria um codigo
Code* CodeNew (char* code, int param);

// deleta um codigo
void CodeDelete (Code* c);

// inicializa o pcode
void PCodeNew(PCode* p);

// delete o pcode
void PCodeDelete (PCode* p);

// insere no comeco
Code* PCodeInsertBegin (PCode *p, char* code, int param);

// insere no proximo
Code* PCodeInsertNext (PCode *p, char* code, int param);

// insere no final 
Code* PCodeInsert (PCode* p, char* code, int param);

// remove do comeco, retornando o codigo q removeu
Code* PCodeRemove (PCode* p);

// numero de linhas de codigo
int PCodeNumLines (PCode* p);

// salva o pcode
void PCodeSave (PCode* p, char* filename);

#endif
