LEX=flex
LEXFLAGS=
LFILES=identificadores.flex

YACC=bison
YACCFLAGS=-d
YFILES=sintatico.y

CC=gcc
CFLAGS=-Wall
CLIBS=
CFILES=$(shell find -name \*.c)
OBJ=LALGC

TESTE=testes/codigo_teste_var.pas

all:
	$(LEX) $(LEXFLAGS) $(LFILES)
	$(YACC) $(YACCFLAGS) $(YFILES)
	$(CC) $(CFLAGS) $(CLIBS) -o $(OBJ) $(CFILES)

run:
	./$(OBJ) $(TESTE)

clean:
	rm -f lex.yy.c sintatico.tab.h sintatico.tab.c LALGC LALGC.zip $(shell find -name \*.o)
	
zip: clean
	zip -r LALGC ../LALGC/

add:
	git add .

commit: clean
	git commit -a -m 'commit default'

pull: add commit
	git pull

push: clean pull
	git push
