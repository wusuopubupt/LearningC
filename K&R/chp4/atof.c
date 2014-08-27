#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

float my_atof(char s[]) {
	int i = 0;
	int sign;
	float n = 0.0;
	int count = 1;

	while (isspace(s[i])) {
		i++;
	}
	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '-' || s[i] == '+') {
		i++;
	}

	while (isdigit(s[i])) {
		n = 10.0 * n + s[i] - '0';
		i++;
	}
	if (s[i] == '.') {
		i++;
	}
	while (isdigit(s[i])) {
		n = 10.0 * n + s[i] - '0';
		count *= 10;
		i++;
	}

	n = sign * n / count;

	int esign, e;
	if (s[i] == 'e' || s[i] == 'E') { /* exponent*/
		esign = (s[++i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (e = 0.0; isdigit(s[i]); i++)
			e = 10.0 * e + (s[i] - '0');
		n *= pow(10, esign * e);
	}
	return n;
}

int main() {
	char s[] = " -2.2e-3";

	float n = atof(s);
	printf("n : %f\n", n);

	return 0;
}
