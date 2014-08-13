#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *join1(char *, char*);
void join2(char *, char *);
char *join3(char *, char*);

int main(void) {
	char a[4] = "abc"; // char *a = "abc"
	char b[4] = "def"; // char *b = "def"

	char *c = join3(a, b);
	printf("Concatenated String is %s\n", c);

	free(c); // free !
	c = NULL;

	return 0;
}

char *join1(char *a, char *b) {
	char *c = (char *) malloc(strlen(a) + strlen(b) + 1); // DO NOT FORGET TO free!
	if (c == NULL) exit (1);
	char *tempc = c;
	while (*a != '\0') {
		*c++ = *a++;
	}
	while ((*c++ = *b++) != '\0') {
		;
	}
	return tempc;
}


void join2(char *a, char *b) {
	while (*a != '\0') {
		a++;
	}
	while ((*a++ = *b++) != '\0') {
		;
	}
}

char* join3(char *s1, char *s2) {
    char *result = malloc(strlen(s1)+strlen(s2)+1);
	if (result == NULL) exit (1);

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}



