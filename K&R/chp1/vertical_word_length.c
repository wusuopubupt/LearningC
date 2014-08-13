/* print horizontal word length histogram */

#include <stdio.h>

#define MAXWORDLEN 11
#define MAXNUM 10

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

	i = MAXNUM;
	while(i) {
		int j = 1;
		while(j < MAXWORDLEN) {
			if(wl[j] >= i) {
				printf(" * ");
			}
			else {
				printf("   ");
			}
			j++;
		}
		printf("\n");

		i--;
	}

	// 1 23 23 123 123 123
	i = 1;
	while(i < MAXNUM) {
		printf(" %d ", i);
		i++;
	}
	printf("\n");

	return 0;
}


