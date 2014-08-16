#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// my_rand() : Return uniform random number in [0, 1]
double my_rand() {
	// rand() : return uniform random number in [0, RAND_MAX]
	return (double)rand() / RAND_MAX;
}

int random(int min, int max) {
	return (int)(my_rand() * (max-min) + min);
}

/*
int main() {
	int min = 5;
	int max = 20;
	int i = 0;
	int n = 100;

	srand(time(NULL));
	while(i < n) {
		int r = random(min, max);
		printf("%d ", r);

		if(r < 5 || r > 20) {
			printf("error!\n");
			break;
		}

		i++;
	}
	printf("\n");

	return 0;
}
*/
