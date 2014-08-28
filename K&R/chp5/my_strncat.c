#include <stdio.h>

void my_strncat(char *s, const char *t, int n) {
	int i = 0;
	while(*s) {
		s++;
	}
	while(*t && i < n) {
		*s = *t;
		s++;
		t++;
		i++;
	}
	*s = '\0';
}

int main() {
	char s[] = "abc";
	char t[] = "def";

	my_strncat(s, t, 2);
	printf("s: %s, t: %s\n", s, t);

	return 0;
}
