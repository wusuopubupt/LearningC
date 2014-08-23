/*
 * Write an alternate version of squeeze(s1,s2) that deletes each
 * character in the string s1 that matches any character in the string s2.
 *
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]) {
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	char c1, c2;
	while((c1 = s1[i]) != '\0') {
		j = 0;
		while((c2 = s2[j]) != '\0') {
			if(c1 == c2) {
				break;
			}
			j++;
		}
		if(c2 == '\0') {
			s1[k++] = c1;
		}

		i++;
	}

	s1[k] = '\0';
}

int main() {
//	char s1[5] = {'a', 'b', 'c', 'd'};
//	char s2[5] = {'x', 'a', 'p', 'c'};

	char s1[] = "abcd";
	char s2[] = "xapc";

	squeeze(s1, s2);

	printf("%s\n", s1);

	return 0;
}
