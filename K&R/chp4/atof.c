#include <stdio.h>
#include <ctype.h>
#include <math.h>

float atof(char s[]) {
	int i = 0;
	int sign;
	float n = 0.0;
	int count = 1;

	while(isspace(s[i])) {
		i++;
	}
	sign = (s[i] == '-') ? -1 : 1;

	if(s[i] == '-' || s[i] == '+') {
		i++;
	}

	while(isdigit(s[i])) {
		n = 10.0 * n + s[i] - '0';
		i++;
	}
	if(s[i] == '.') {
		i++;
	}
	while(isdigit(s[i])) {
		n = 10.0 * n + s[i] - '0';
		count *= 10;
		i++;
	}

	return sign * n / count;
}

int main() {
	char s[] = " 	-10.65";

	float n = atof(s);
	printf("n : %f\n", n);

	return 0;
}
