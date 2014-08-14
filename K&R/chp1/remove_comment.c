/**
 * remove all comment in a program.
 */
#include <stdio.h>

void echo_quote(int c) {
	int d;
	putchar(c);
	while((d = getchar()) != c) { /* search for the end */
		putchar(d);
		if(d == '\\') {
			putchar(getchar());
		}
	}
	putchar(d);
}

void in_comment() {
	int c, d;
	c = getchar();
	d = getchar();
	while(c != '*' || d != '/') {
		c = d;
		d = getchar();
	}
}

/* read each character, remove the comments */
void remove_comment(int c) {
	int d;

	if(c == '/') {
		if((d = getchar()) == '*') { /* beginning comment */
			in_comment();
		}
		else if(d == '/') { /* another comment */
			putchar(c);
			remove_comment(d);
		}
		else {	/* not a comment */
			putchar(c);
			putchar(d);
		}
	}
	else if(c == '\'' || c == '"') {
		echo_quote(c);
	}
	else {
		putchar(c);
	}
}

int main() {
	int c;
	while((c = getchar()) != EOF) {
		remove_comment(c);
	}
	return 0;
}
