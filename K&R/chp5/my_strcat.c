#include <stdio.h>

void my_strcat(char *s1, const char *s2) {
	while(*s1) {
		s1++;
	}
	while(*s2) {
		*s1++ = *s2++;
	}
	*s1 = '\0';
}

int main() {
	char s1[100] = "abc";
	char s2[10] = "def";

	my_strcat(s1, s2);
	printf("s1: %s, s2: %s\n", s1, s2);

	return 0;
}
