/*
 * Write the function strend(s,t), which returns 1 if the string t
 * occurs at the end of the string s, and zero otherwise.
 */
#include <stdio.h>

int strend(char *s, char *t) {
	int len_s = 0;
	int len_t = 0;

	while(*s != '\0') {
		s++;
		len_s++;
	}
	while(*t != '\0') {
		t++;
		len_t++;
	}
	if(len_s < len_t) {
		return 0;
	}
	else {
		int i = len_t;
		while(i) {
			if(*s == *t) {
				s--;
				t--;
			}
			else {
				return 0;
			}
			i--;
		}
		if(i == 0) {
			return 1;
		}
	}


}

int main() {
	char *s = "abcdef";
	char *t = "def";

	printf("%d\n", strend(s, t));
	return 0;
}
