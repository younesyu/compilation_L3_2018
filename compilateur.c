#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboles.h"
#include "util.h"
#include "analyseur_syntaxique.h"

int yylex(void);
extern char *yytext;
FILE *yyin;

int main(int argc, char **argv) {  
	yyin = fopen(argv[1], "r");

	if(yyin == NULL) {
		fprintf(stderr, "impossible d'ouvrir le fichier %s\n", argv[1]);
		exit(1);
	}

	uniteCourante = yylex();  
	E();

	if (uniteCourante == FIN) return 0;
	printf("Erreur de syntaxe.\n");
	return 1;
}