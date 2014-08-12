#include <stdio.h>

int main() {
	int c;
	int n_blank = 0;
	int n_tab = 0;
	int n_newline = 0;

	while((c = getchar()) != EOF) {
		if(c == ' ') {
			n_blank++;
		}
		else if(c == '\t') {
			n_tab++;
		}
		else if(c == '\n') {
			n_newline++;
		}
	}

	printf("n_blank:%d n_tab:%d n_newline:%d\n", n_blank, n_tab, n_newline);
	return 0;
}
