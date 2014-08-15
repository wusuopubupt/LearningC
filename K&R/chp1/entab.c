#include <stdio.h>

#define TABNUM 8

int main() {
	int c, nb, nt, pos;

	nb = 0;
	nt = 0;
	for(pos = 1; (c = getchar()) != EOF; ++pos) {
		if(c == ' ') {
			if(pos % TABNUM != 0) {
				++nb;
			}
			else {
				nb = 0;
				++nt;
			}
		}
		else {
			while(nt) {
				putchar('\t');
				--nt;
			}
			if(c == '\t') {
				nb = 0;
			}
			else {
				while(nb) {
					putchar(' ');
					--nb;
				}
			}
			putchar(c);
			if(c == '\n') {
				pos = 0;
			}
			else if(c == '\t') {
				pos = pos + (TABNUM - (pos-1) % TABNUM) - 1;
			}
		}
	}
}
