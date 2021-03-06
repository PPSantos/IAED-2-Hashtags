#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtag.h"

/*Construtor*/
hashtag newHASHTAG(char* message){

	hashtag c = (hashtag)malloc(sizeof(struct hashtag));

	c->name = strdup(message);
	c->num = 1;
	return c;
}

/* Prints */
void printHASHTAG(hashtag a){ printf("%s %d\n", a->name, a->num); }

/* Testes */
int existsHASHTAG(hashtag a){ return (a != NULL); }

/* Mutadores */
void incHASHTAG(hashtag a){ a->num++; }

/* Acessorios */
int numHASHTAG(hashtag a){ return a->num; }
char* nameHASHTAG(hashtag a){ return a->name; }

/* Verifica qual a maior hashtag quando introduzida uma nova no sistema */
void highestHASHTAG(hashtag c, hashtag aux, char* buffer){

	if (c == NULL){
		if (numHASHTAG(highest) == 1){
			if( less(buffer, nameHASHTAG(highest))){
				highest = aux;
			}
		}
	}

	else if (numHASHTAG(highest) < numHASHTAG(c)){
		highest = c;
	}

	else if ( numHASHTAG(highest) == numHASHTAG(c)){
		if (less(buffer, nameHASHTAG(highest)))
			highest = c;
	}	

}
