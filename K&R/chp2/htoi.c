#include <stdio.h>

int htoi(char s[]) {
	int i, n;
	char c;
	int is_hex = 0;
	n = 0;

	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		is_hex = 1;
	}

	if(is_hex) {
		i = 2;
		while((c = s[i]) != '\0') {
			if(c >= '0' && c <= '9') {
				n = n*16 + c - '0';
			}
			else if(c >= 'a' && c <= 'f') {
				n = n*16 + 10 + c - 'a';
			}
			else if(c >= 'A' && c <= 'F') {
				n = n*16 + 10 + c - 'A';
			}

			i++;
		}
	}

	return n;
}

int main() {
	//char *s = "oX10"; Error!
	//char s[] = {'0', 'X', '1', '0'};
	char s[1024];
	int i, c;
	for (i=0; (c = getchar()) != '\n'; i++) {
		s[i] = c;
	}
	s[i] = '\0';

	printf("%d\n", htoi(s));

	return 0;
}
