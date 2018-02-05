#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboles.h"
#include "util.h"
#include "analyseur_syntaxique.h"

int yylex(void);
extern char *yytext;
FILE *yyin;

void next() {
	printf("%s", yytext);
	uniteCourante = yylex();
}

void E (void) {
	T();
	EPrime();
	
}

void N() {
	if (uniteCourante == NON) {
		next();
		N();
	}

	E();
}

 void F (void) {
 	if (uniteCourante == PARENTHESE_OUVRANTE) {
		next();
 		E();
 		if (uniteCourante == PARENTHESE_FERMANTE) {
			next();
 			return;
 		}
 		else goto erreur;
 	}
 	else if (uniteCourante == NOMBRE || uniteCourante == ID_VAR) {
		next();
 		return;
 	}
 	erreur:
 		printf("\nErreur de syntaxe : %s, %s.\n", yytext, __func__);

 }

void T (void) {
	F();
	TPrime();
}

void EPrime (void) {
	if(uniteCourante == PLUS || uniteCourante == MOINS) {
		next();
		E();
	}
}

void TPrime (void) {
	if(uniteCourante == FOIS || uniteCourante == DIVISE) {
		next();
		T();
	}
}

