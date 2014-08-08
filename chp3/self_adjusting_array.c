#include <stdio.h>
#include <stdlib.h>

static int find_array(int *a, int n, int x) {
	int i = 0;
	int found = 0;
	while(i < n) {
		if(a[i] == x) {
			found = 1;
			break;
		}
		i++;
	}

	if(found) {
		int j = 0;
		for(j = i; j > 0; j--) {
			a[j] = a[j-1];
		}
		a[0] = x;
	}

	return found;
}
int main() {
	int a[5] = {1, 4, 9, 16, 25};

	int found = find_array(a, 5, 9);

	int i = 0, n = 5;
	while(i < n) {
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");

	return 0;
}
