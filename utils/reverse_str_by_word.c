/*
 * @author  : wusuopubupt
 * @date	: 2014-10-20
 * @desc	: reverse string, keep world
 */
#include <stdio.h>
#include <ctype.h>

void reverse_str(char *s, int i, int j) {
	while(i < j) {
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

int main() {
	char s[] = "hello, world";
	int n = sizeof(s)/sizeof(s[0]);
	reverse_str(s, 0, n-2);
	//dlrow ,olleh

	int i = 0, j = 0;
	while(s[i] != '\0') {
		while(isalnum(s[j])) {
			j++;
		}
		reverse_str(s, i, j-1);
		i = ++j;
	}

	printf("%s\n", s);

	return 0;
}

