#include <stdio.h>

int my_strcmp(const char *s, const char *t) {
	while(*s != '\0' && *t != '\0' && *s == *t) {
		s++;
		t++;
	}

	return *s - *t;
}

int main() {
	char *s = "abc";
	char *t = "abd";

	printf("%d\n", my_strcmp(s, t));
	return 0;
}
