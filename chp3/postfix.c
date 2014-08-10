
/**
 * @author : dash
 * @desc : reverse Polish calculator
 * @reference : K&R 4.3
 * @usage : when you want to calculater (1 - 2) * (4 + 5), just input: 1 2 - 4 5 + *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'

void push(double);
double pop();
int getch();
int ungetch(int c);
int getop(char []);

int sp = 0;
int bufp = 0;
double val[MAXVAL];
char buf[BUFSIZE];

void print_array(int val[], int n) {
	int i = 0;
	printf("\n ----debuf-----\n");
	while(i < n) {
		printf("%d ", val[i]);
		i++;
	}
	printf("\n");
}

void push(double f) {
	if(sp < MAXVAL) {
		val[sp++] = f;
	}
	else {
		printf("stack if full!\n");
	}
}

double pop() {
	if(sp > 0) {
		return val[--sp];
	}
	else {
		printf("stack is empty!\n");
	}
}

int getch() {
	int c = (bufp > 0) ? buf[--bufp] : getchar();// if buffer has character, return, else getchar()
	//printf("bufp:%d, c: %c, %d\n", bufp, (char)c, c);
	return c;
}

int ungetch(int c) {
	if(bufp >= BUFSIZE) {
		printf("too much characters!\n");
	}
	else {
		buf[bufp++] = c; // put character c back to input buffer
	}
}

int getop(char s[]) {
	int i = 0, c;
	while((s[0] = c = getch()) == ' ' || c == '\t') {
		continue;
	}

	s[1] = '\0';
	if(!isdigit(c) && c != '.') {
		return c; // c is operator
	}
	if(isdigit(c)) {
		while(isdigit(s[++i] = c = getch())) {
			continue;
		}
	}
	if(c == '.') {
		while(isdigit(s[++i] = c = getch())) {
			continue;
		}
	}
	s[i] = '\0';
	if(c == EOF) {
		ungetch(c);
	}

	return NUMBER; // c is number
}

int main() {
	int type;
	double op2;
	char s[MAXOP];

	// input : 2 1 -
	while((type = getop(s)) != EOF) {
		//printf("type: %d, %c\n", type, (char)type);
		switch(type) {

		print_array(val, sp);

		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2); // CAN NOT BE pop() - pop() !
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0) {
				push(pop() / op2);
			}
			else {
				printf("divide by 0!\n");
			}
			break;
		case '\n':
			printf("The result is: %.8f\n", pop());
			break;
		default:
			printf("error: unknown cmd: %s!\n", s);
			break;
		}
	}

	return 0;
}





