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
	extern int brace, brack, paren;
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
	else if(c == '(') {
		++paren;
	}
	else if(c == ')') {
		--paren;
	}
}

int main() {
	int c, d;
	extern int brace, brack, paren;
	while((c = getchar()) != EOF) {
		if(c == '/') {
			if((d = getchar()) == '*') {
				in_comment();
			}
			else {
				search(c);
			}
		}
		else if(d == '\'' || d == '"') {
			in_quote(c);
		}
		else {
			search(c);
		}

		if(brace < 0) {
			printf("Unbalanced braces\n");
			brace = 0;
		}
		if(brack < 0) {
			printf("Unbalanced brackets\n");
			brack = 0;
		}
		if(paren < 0) {
			printf("Unbalanced parentheses\n");
			paren = 0;
		}
	}

	if(brace > 0) {
		printf("Unbalanced braces\n");
	}
	if(brack > 0) {
		printf("Unbalanced brackets\n");
	}
	if(paren > 0) {
		printf("Unbalanced parentheses\n");
	}
	return 0;
}
