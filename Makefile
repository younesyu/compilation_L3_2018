CC = gcc
FLEX = ./flex

LIBS = -lm 
CCFLAGS = -Wall -ggdb

OBJ = analyseur_lexical_flex.o util.o analyseur_syntaxique.o 

all: compilateur

compilateur: compilateur.c $(OBJ) 
	$(CC) $(CCFLAGS) -o compilateur compilateur.c $(OBJ)

#test_yylex: test_yylex.c $(OBJ)
#	$(CC) $(CCFLAGS) -o test_yylex test_yylex.c $(OBJ)

analyseur_lexical_flex.c: analyseur_lexical.flex
	$(FLEX) -o $@ $^

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

.PHONY : clean

clean:
	- rm -f *.o
	- rm -f compilateur
	- rm -f analyseur_lexical_flex.c
