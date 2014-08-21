#include <stdio.h>

#define TABNUM 8

/*
int main() {
	int c, nb, nt;
	nb = 0;
	nt = 0;

	//a       9   3           11
	while((c = getchar()) != EOF) {
		if(c == ' ') {
			nb++;
		}
		else {
			nt = nb / TABNUM;
			nb = nb % TABNUM;

			//printf("nb:%d, nt:%d\n", nb, nt);

			while(nt) {
				putchar('\t');
				nt--;
			}
			while(nb) {
				putchar(' ');
				nb--;
			}
			putchar(c);
		}
	}

	return 0;
}
*/
