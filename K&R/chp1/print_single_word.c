#include <stdio.h>

int main() {
	int c;
	while((c = getchar()) != EOF) {
		int printed = 0;
		if(c != ' ' && c != '\t' && c != '\n') {
			putchar(c);
			printed = 0;
		}
		else if(!printed) {
			putchar('\n');
			printed = 1;
		}
	}
	return 0;
}
