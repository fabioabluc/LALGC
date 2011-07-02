LEX=flex
LEXFLAGS=
LFILES=identificadores.flex

YACC=bison
YACCFLAGS=-d
YFILES=sintatico.y

CC=gcc
CFLAGS=-Wall
CLIBS=
HFILES=$(shell ls *.h)
CFILES=$(shell ls *.c)
OBJ=LALGC

TESTE=testes/codigo_teste2.pas

all:
	$(LEX) $(LEXFLAGS) $(LFILES)
	$(YACC) $(YACCFLAGS) $(YFILES)
	$(CC) $(CFLAGS) $(CLIBS) -o$(OBJ) $(CFILES)

run:
	./$(OBJ) $(TESTE)

clean:
	rm -f lex.yy.c sintatico.tab.h sintatico.tab.c LALGC LALGC.zip
	
zip: clean
	zip -r LALGC ../LALGC/
