#include <stdio.h>

int binary_search(const int *a, int n, int x) {
	int low = 0, high = n, mid;
	while(low <= high) {
		mid = low+ (high-low)/2;
		if(a[mid] == x) {
			return mid;
		}
		else if(a[mid] > x) {
			high = mid -1;
		}
		else {
			low = mid + 1;
		}
	}

	return -1;
}



int main() {
	int a[2] = {1, 2};
	int find = binary_search(a, 5, 3);
	printf("find index is:%d\n", find);

	return 0;
}
