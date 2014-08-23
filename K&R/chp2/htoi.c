/*
 * Write the function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer
 * value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

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
	char *s = "0X10";
	//char s[] = {'0', 'X', '1', '0'};
//	char s[1024];
	int i, c;
//	for (i=0; (c = getchar()) != '\n'; i++) {
//		s[i] = c;
//	}
//	s[i] = '\0';

	printf("%d\n", htoi(s));

	return 0;
}
