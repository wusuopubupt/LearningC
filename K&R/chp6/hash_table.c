/*
 * My practice of K&R 6.6
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct nlist_ {
	char *name;
	char *defn;
	struct nlist_ *next;
} nlist;

#define HASHSIZE 101
static nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
	unsigned hashval = 0;
	while(*s != '\0') {
		hashval = *s + 31 * hashval;
		s++;
	}
	return hashval % HASHSIZE;
}

nlist *lookup(char *s) {
	nlist *np;
	int index = hash(s);
	np = hashtab[index];
	while(np != NULL) {
		if(strcmp(np->name, s) == 0) {
			return np;
		}
 		np++;
	}
	return NULL;
}

char *copy_string(char *s) {
	char *p = (char *)malloc(strlen(s)+1); /* DO NOT FORGET TO free ! */
	if(p) {
		strcpy(p, s);
	}
	return p;
}

nlist *install(char *name, char *defn) {
	nlist *np = NULL;
	unsigned hashval;

	if((np = lookup(name)) == NULL) {
		np = (nlist *)malloc(sizeof(nlist));
		if(np == NULL || (np->name = copy_string(name)) == NULL) {
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else {
		free((void*)np->defn);
	}

	np->defn = copy_string(defn);
	if(np->defn) {
		return np;
	}
	else {
		return NULL;
	}
}


int main() {

	return 0;
}
