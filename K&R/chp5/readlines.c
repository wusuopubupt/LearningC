#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES  5
#define MAXLEN    100

char *lineptr[MAXLINES];

int getline(char s[], int max_len) {
	int i = 0;
//	int c;
//	while(i < max_len && (c = getchar()) != EOF && c != '\n' ) {
//		s[i++] = c;
//	}
//	if(c == '\n') {
//		s[i++] = c;
//	}
//	s[i] = '\0';

	*s = 'a';
	*(s+1) = 'b';
	*(s+2) = 'c';
	*(s+3) = '\0';

	i = 3;

	return i;
}

int readlines(char *lineptr[], int maxlines) {
	int i = 0;
	int len;

	char *line = lineptr[i++];


	while(i < maxlines && (len = getline(line, MAXLEN)) > 0) {
		printf("i: %d, line: %s\n", i, line);
		line = lineptr[i++];
	}
	return i;
}

void writelines(char *lineptr[], int n_line) {
	int i = 0;
	while(i < n_line) {
		printf("%s\n", lineptr[i]);
		i++;
	}
}
int main() {
	int n_line;

	if((n_line = readlines(lineptr, MAXLINES)) >= 0) {
		writelines(lineptr, n_line);
		return 0;
	}
	else {
		printf("error\n");
		return 1;
	}
}
