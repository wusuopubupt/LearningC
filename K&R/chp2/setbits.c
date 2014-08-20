#include <stdio.h>
#define MAXCHAR 100

void itob(unsigned x, char s[]);
unsigned setbits(unsigned x, int p, int n, unsigned y);

/*
int main() {
	int x = 0, p = 0, n = 0, i = 0;
	unsigned int m = 0;
	unsigned int y = 0;
	char binary_unit[MAXCHAR];
	for (i = 0; i < MAXCHAR - 1; i++) {
		binary_unit[i] = 0;
	}

	x = 170;                                    //10101010b;
	y = 15;                                     //00001111b;

	p = 1;
	n = 3;

	printf("test 1:\n");
	itob(x, binary_unit);
	printf("x=%u=%sb\t", x, binary_unit);
	itob(y, binary_unit);
	printf("y=%u=%sb\t", y, binary_unit);
	printf("p=%d\tn=%d\n", p, n);

	m = setbits(x, p, n, y);                       //10101110b;174
	itob(m, binary_unit);
	printf("changed x=%d=%sb\n\n", m, binary_unit);

	p = 4;
	n = 2;
	printf("test 2:\n");
	itob(x, binary_unit);
	printf("x=%u=%sb\t", x, binary_unit);
	itob(y, binary_unit);
	printf("y=%u=%sb\t", y, binary_unit);
	printf("p=%d\tn=%d\n", p, n);

	m = setbits(x, p, n, y);                       //10111010b;186
	itob(m, binary_unit);
	printf("changed x=%d=%sb\n\n", m, binary_unit);

	return 0;
}
unsigned setbits(unsigned x, int p, int n, unsigned y) {
	return (x & ~((~(~0 << n)) << p) | ((y << p) & ((~(~0 << n)) << p)));
}
void itob(unsigned x, char s[]) {
	int i = 0, n = 0;
	char temp[MAXCHAR];

	while ((x / 2) != 0) {
		temp[n] = ((x % 2) + '0');
		x /= 2;
		n++;
	}
	temp[n] = ((x % 2) + '0');
	temp[n + 1] = '\0';

	i = 0;
	while (n >= 0) {
		s[i] = temp[n--];
		i++;
	}
	s[i] = '\0';
}
*/
