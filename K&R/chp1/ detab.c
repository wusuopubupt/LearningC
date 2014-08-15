#include <stdio.h>

#define TABNUM 8

int main() {
	int c, nb, pos;

	nb = 0;
	pos = 1;
	while((c = getchar()) != EOF) {
		if(c == '\t') {
			nb = TABNUM - (pos-1) % TABNUM;
			while(nb > 0) {
				putchar(' ');
				++pos;
				--nb;
			}
		}
		else if(c == '\n') { /* new line */
			putchar(c);
			pos = 1;
		}
		else {
			putchar(c);
			++pos;
		}
	}
}
