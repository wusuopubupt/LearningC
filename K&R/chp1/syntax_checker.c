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

void search(int c) {
	int brace, brack, paren;
	if(c == '{') {
		++brace;
	}
	else if(c == '}') {
		--brace;
	}
	else if(c == '[') {
		++brack;
	}
	else if(c == ']') {
		--brack;
	}
}

int main() {
	int c;

	return 0;
}
