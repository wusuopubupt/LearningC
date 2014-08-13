/* print horizontal word length histogram */

#include <stdio.h>

#define MAXWORDLEN 11

int wl[MAXWORDLEN]; // word length counter

int main() {
	int i = 0;
	int c = 0;
	int len = 0;
	int end_word = 0;
	while((c = getchar()) != EOF) {
		if(c != ' ' && c != '\t' && c!= '\n') {
			len++;
			end_word = 0;
		}
		else {
			end_word = 1;
		}

		if(end_word) {
			wl[len]++;
			len = 0;
		}
	}


	i = 1;
	while(i < MAXWORDLEN) {
		printf("%d ", i);
		int j = 0;
		while(j < wl[i]) {
			putchar('*');
			j++;
		}
		putchar('\n');
		i++;
	}

	return 0;
}


