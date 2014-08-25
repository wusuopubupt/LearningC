/*


*/
#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
	return a+b;
}

int subtract(int a, int b) {
	return a-b;
}

typedef int (*fptrOperation)(int, int);

int compute(fptrOperation operation, int num1, int num2) {
	return operation(num1, num2);
}

int main() {
	printf("%d\n", compute(add, 5, 6)); // 11
	printf("%d\n", compute(subtract, 5, 6)); // -1

	return 0;
}
