#include <stdio.h>
#include <math.h>

int is_prime(int n) {
	int is_prime = 1, i, max;
	if(n == 1) {
		return 0;
	}

	i = 2, max = (int)sqrt(n) + 1;
	while(i < max) {
		printf("i:%d, max:%d\n", i, max);
		if (n % i == 0 && n != i) {
			is_prime = 0;
			break;
		}
		i++;
	}

	return is_prime;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%d is prime: %s\n", n, is_prime(n) ? "true" : "false");
	}
	return 0;
}
