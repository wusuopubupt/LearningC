#include <stdio.h>

int my_atoi(char s[]) {
	int i, n;
	n = 0;
	i = 0;
	while(s[i] >= '0' && s[i] <='9') {
		n = n * 10 + (s[i] - '0');
		i++;
	}

	return n;
}

int main() {
	char s[] = {'1', '2', '3'};
	int n = my_atoi(s);
	printf("%d\n", n);
	return 0;
}
