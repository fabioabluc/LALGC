#include "Simble.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// novo simbolo
Simble *SimbleNew() {
	Simble *s = (Simble*) malloc(sizeof(Simble));
	strcpy(s->name, "");
	s->classe = 0;
	s->type = 0;
	s->value = 0;
	s->number = 0;
	s->argument = 0;
	s->from_proc = 0;

	return s;
}

// deleta o simbolo
void SimbleDelete(Simble* s) {}

// define o nome do simbolo
void SimbleSetName(Simble *s, char* newName) {
	strcpy(s->name, newName);
}

char* SimbleToString (Simble*s) {
	char *str = (char*) malloc(sizeof(char) * (255 + 1));
	sprintf(str, "%s %d %d %.2f %d %d %d",
		s->name,
		s->classe,
		s->type,
		s->value,
		s->number,
		s->argument,
		s->from_proc); 
	return str;
}
