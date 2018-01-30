#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboles.h"
#include "util.h"
#include "analyseur_syntaxique.h"

int yylex(void);
extern char *yytext;
FILE *yyin;

void E (void) {
	printf("Appel de %s\n", __func__);
	T();
	EPrime();
}

 void F (void) {
 	printf("Appel de %s\n", __func__);
 	if (uniteCourante == PARENTHESE_OUVRANTE) {
 		uniteCourante = yylex();
 		E();
 		if (uniteCourante == PARENTHESE_FERMANTE) {
 			uniteCourante = yylex();
 			return;
 		}
 		else goto erreur;
 	}
 	else if (uniteCourante == NOMBRE) {
 		uniteCourante = yylex();
 		return;
 	}
 	erreur:
 		printf("Erreur de syntaxe : %d, %s.\n", uniteCourante, __func__);
		exit (-1);

 }

void T (void) {
	printf("Appel de %s\n", __func__);
	F();
	TPrime();
}

void EPrime (void) {
	printf("Appel de %s\n", __func__);

	if(uniteCourante == PLUS || uniteCourante == MOINS) {
		uniteCourante = yylex();
		E();
	}
}

void TPrime (void) {
	printf("Appel de %s\n", __func__);

	if(uniteCourante == FOIS || uniteCourante == DIVISE) {
		printf("la 2\n");
		uniteCourante = yylex();
		T();
	}
}
