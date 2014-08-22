#include <stdio.h>
/*
int bit_count(int x) {
    int count = 0;
	for(count = 0; x != 0; x &= (x-1)) {
		count++;
	}
	return count;
}
*/

int bit_count2(int x) {
	int count = 0;
	while(x) {
		count++;
		x &= (x-1);
	}
	return count;
}

int main() {
	int a = 3;
	printf("bit count:%d\n", bit_count2(a));
	return 0;
}

