#include <stdio.h>

int main() {
	int pre_is_blank = 0;
	int c;
	while((c = getchar()) != EOF) {
		if(c != ' ' && c != '\t') {
			putchar(c);
		}
		else if(!pre_is_blank) {
			if(c == ' ') {
				putchar(c);
			}
			else if(c == '\t') {
				putchar(' ');
			}
		}

		if(c == ' ' || c == '\t') {
			pre_is_blank = 1;
		}
		else {
			pre_is_blank = 0;
		}
	}

	return 0;
}
