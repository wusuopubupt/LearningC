/**
 * reference : http://en.wikipedia.org/wiki/Function_pointer
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef int(*fp_operation)(int a, int b);

int add(int a, int b);
int subtract(int a, int b);
int compute(fp_operation op, int a, int b);

int main() {
	printf("%d\n", compute(add, 5, 6)); // 11
	printf("%d\n", compute(subtract, 5, 6)); // -1

	return 0;
}

int add(int a, int b) {
	return a+b;
}

int subtract(int a, int b) {
	return a-b;
}

int compute(fp_operation operation, int num1, int num2) {
	return operation(num1, num2);
}
