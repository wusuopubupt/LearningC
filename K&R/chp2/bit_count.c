#include <stdio.h>

int bit_count(int x) {
    int count = 0;
	for(count = 0; x != 0; x &= (x-1)) {
		count++;
	}
	return count;
}

int bit_count2(int x) {
	int count = 0;
	while(x) {
		if((x &= (x-1)) != 0) {
			count++;
		}
	}
	return count;
}
/*
int main() {
	int a = 10;
	printf("bit count:%d\n", bit_count(a));
	return 0;
}
*/
