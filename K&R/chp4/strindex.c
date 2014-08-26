/*
 * Write the function strrindex(s,t), which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none.
 */
#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]) {
	int i = 0, j = 0;
	int s_len = strlen(s);
	int t_len = strlen(t);
	int index = -1;

	while(i < s_len && s[i] != t[0]) {
		i++;
	}
	while(i < s_len && j < t_len && (s[i++] == t[j++])) {
		if(t[j] == '\0') {
			index = i - strlen(t); // 3, 6 -> we choose the "rightmost" one : 6
			j = 0;
		}
		while(i < s_len && s[i] != t[j]) {
			i++;
		}
	}

	return index;
}

int main() {
	char *s = "abcdefdef";
	char *t = "de";

	int index = strindex(s, t);
	printf("index: %d\n", index); // 6

	return 0;
}
