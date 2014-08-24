#include <stdio.h>
#include <string.h>

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[]) {
	int n = strlen(s) - 1;
	while (n) {
		if (s[n] == ' ' || s[n] == '\t' || s[n] == '\n') {
			n--;
		} else {
			break;
		}
	}
	s[n+1] = '\0';

	return n;
}

int main() {
	char s[] = "abc 		";
	trim(s);
	printf("s:%s, strlen:%d\n", s, strlen(s));

	return 0;
}
