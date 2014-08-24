#include <stdio.h>

int binary_search(const int *a, int n, int x) {
	int low = 0, high = n, mid, found = -1;
	while(low <= high) {
		mid = low + (high-low)/2;
		if(a[mid] > x) {
			high = mid - 1;
		}
		else {
			found = mid;
			low = mid + 1;
		}
	}

	return (found != -1 && a[found] == x ? found : -1);
}

int main() {
	int a[5] = {1, 2, 3, 4, 5};
	int find = binary_search(a, 5, 2);
	printf("find index is:%d\n", find);

	return 0;
}
