#include <stdio.h>
#include <string.h>

void eacape(char s[], char t[]) {
	int i = 0, j = 0;
	while(t[i] != '\0') {
		switch(t[i]) {
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';
}

int main(void) {
    char s[50];
    char t[20] = "just \t for a test\n\n !";
    escape(s, t);
    printf("%s\n", s);
    return 0;
}
