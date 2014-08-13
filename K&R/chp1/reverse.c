#include <stdio.h>

/* O(log n) */
void reverse(char s[]) {
	int i = 0;
	while(s[i] != '\0') {
		i++;
	}
	int high = i-1;
	int low = 0;

	while(low < high) {
		int temp = s[low];
		s[low] = s[high];
		s[high] = temp;
		low++;
		high--;
	}
}


int main() {
	char s[] = {'h', 'e', 'l', 'l', 'o', '\0'};
	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);

	return 0;
}
