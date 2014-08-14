#include <stdio.h>

int brace, brack, paren;

static void in_comment() {
	int c, d;
	c = getchar();
	d = getchar();
	while(c != '*' || d != '/') {
		c = d;
		d = getchar();
	}
}

static void in_quote(int c) {
	int d;
	while((d = getchar()) != c) {
		if(d == '\\') {
			getchar();
		}
	}
}

int main() {
	int c;

	return 0;
}
