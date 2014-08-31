#include <stdio.h>

int my_strlen(char *s) { // or char s[]
	int n = 0;
	while(*s != '\0') {
		n++;
		s++;
	}
	return n;
}

int main() {
	char *s1 = "hello";
	char s2[] = "hello";

	printf("strlen s1: %d\n", my_strlen(s1));
	printf("strlen s2: %d\n", my_strlen(s2));

	return 0;
}
