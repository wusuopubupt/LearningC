/*
 * Practice of struct array. K&R 6-1
 * @author : wusuopubupt
 * @date   : 2014-09-18
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

typedef struct key_{
	char *word;
	int count;
} key;

key key_tab[] = {
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"for", 0},
	{"int", 0},
	{"void", 0},
	{"while", 0}
};

int getword(char *word, int n);
int binary_search(key key_tab[], char *word, int n);

int main() {
	int i;
	int n_keys = sizeof(key_tab) / sizeof(key_tab[0]);
	char word[MAXWORD];

	while(getword(word, MAXWORD) != EOF) {
		if(isalpha(word[0])) {
			if((i = binary_search(key_tab, word, n_keys)) >= 0) {
				key_tab[i].count++;
			}
		}
	}

	i = 0;
	while(i < n_keys) {
		printf("%s : %d\n", key_tab[i].word, key_tab[i].count);
		i++;
	}

	return 0;
}

int getword(char *word, int n) {
	int c;
	char *w = word;

	while(isspace(c = getchar())) {
		;
	}
	if(c != EOF) {
		*w++ = c;
	}
	if(!isalpha(c)) {
		*w = '\0';
		return c;
	}
	while(n > 0) {
		c = getchar();
		if(isalnum(c)) {
			*w++ = c;
		}
		else {
			break;
		}
		n--;
	}

	*w = '\0';
	return w[0];
}

int binary_search(key key_tab[], char *word, int n) {
	int low = 0;
	int high = n-1;
	int mid;
	int result;
	while(low <= high) {
		mid = (low+high) / 2;
		result = strcmp(word, key_tab[mid].word);
		if(result < 0) {
			high = mid-1;
		}
		else if(result > 0) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
