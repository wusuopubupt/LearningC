#include <stdio.h>

void my_strncpy(char *s, const char *t, int n) {
	int i = 0;
	while(i < n && *t != '0') {
		*s = *t;
		s++;
		t++;
		i++;
	}
	*s = '\0';
}

int main() {
	char s[100];
	char t[] = "def";

	my_strncpy(s, t, 2);
	printf("s: %s, t: %s\n", s, t);

	return 0;
}
