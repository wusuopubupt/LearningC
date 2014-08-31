#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 3

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int getint(int *pn) {
	int c, sign = 1;

	c = getch();
	while(isspace(c)) {
		c = getch();
	}
	if(c != '+' && c != '-' && !isdigit(c) && c != EOF) {
		ungetch(c);
		return 0;
	}

	if(c == '+' || c == '-') {
		if(c == '-') {
			sign = -1;
		}

		c = getch();
		if(!isdigit(c)) {
			ungetch(c);
			ungetch(sign == 1 ? '+' : '-');
			return 0;
		}
	}

	*pn = 0;
	while(isdigit(c)) {
		*pn = *pn * 10 + c - '0';
		c = getch();
	}
	*pn *= sign;
	if(c != EOF) {
		ungetch(c);
	}
	return c;
}

int main(void) {
	int n, r;

	r = getint(&n);

	if (r > 0) {
		printf("%d\n", n);
	}
	else if (r == 0) {
		printf("not a number\n");
	}
	else if (r == EOF) {
		printf("end of file\n");
	}
	else {
		printf("error!\n");
	}

	return 0;
}
