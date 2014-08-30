#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES  100
#define MAXLEN    100

static int get_line(char s[], int max_len);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int maxlines);

static int get_line(char s[], int max_len) {
	int i = 0;
	int c;

	while(i < max_len && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if(c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';

	return i;
}

int readlines(char *lineptr[], int maxlines) {
	int i = 0;
	int len;

	char *line = lineptr[i];
	while(i < maxlines && (len = get_line(line, MAXLEN)) > 0) {
		//printf("i: %d, line: %s", i, line);
		line = lineptr[++i];
	}
	return i;
}

void writelines(char *lineptr[], int n_line) {
	int i = 0;
	while(i < n_line) {
		printf("%s", lineptr[i]);
		i++;
	}
}

int main1() {
	int flag, n_line;
	int i = 0;
	char **lineptr = (char **)malloc(sizeof(char *) * MAXLINES);
	while(i < MAXLINES) {
		lineptr[i] = (char *)malloc(sizeof(char) * MAXLEN);
		i++;
	}

	if((n_line = readlines(lineptr, MAXLINES)) >= 0) {
		printf("\n");
		writelines(lineptr, n_line);
		flag = 1;
	}
	else {
		printf("error\n");
		flag = 0;
	}

	/* free */
	if(lineptr) {
		int i = 0;
		while(i < MAXLINES) {
			if(lineptr[i]) {
				free(lineptr[i]);
			}
			i++;
		}
		free(lineptr);
	}

	if(flag) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int c;
	int i = 0;
	char **lineptr = (char **)malloc(sizeof(char *) * MAXLINES);
	while(i < MAXLINES) {
		lineptr[i] = (char *)malloc(sizeof(char) * MAXLEN);
		i++;
	}

	char *line = lineptr[0];
	int j = 0;
	while((c = getchar()) != EOF) {
		if(c != '\n') {
			line[j++] = c;
		}
		else {
			line[j] = '\n';
			line[j+1] = '\0';
			j = 0;
			line = lineptr[++i];
		}
	}

	writelines(lineptr, i);

	/* free */
	if(lineptr) {
		int i = 0;
		while(i < MAXLINES) {
			if(lineptr[i]) {
				free(lineptr[i]);
			}
			i++;
		}
		free(lineptr);
	}

	return 0;
}


