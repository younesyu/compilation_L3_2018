/*
 * Analyseur lexical du compilateur L en FLEX
 */
 
%{
#include "symboles.h"
%}
%option yylineno
%option nounput
%option noinput

/* Déclarations à compléter ... */

%%
<<EOF>>              { return FIN;                 }  /* Fin de fichier */

%%
int yywrap(){
  return 1;
}

