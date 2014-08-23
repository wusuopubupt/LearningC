#include <stdio.h>

int lower(int c) {
	return c > 'A' && c < 'Z' ? (c + 'a' - 'A') : c;
}

int main() {
	char c = 'B';

	int cc = lower(c);
	printf("lower: %c\n", cc);

	return 0;
}
