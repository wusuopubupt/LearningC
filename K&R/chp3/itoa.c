/*
 * Convert int to string
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[], int n) {
	int i = 0, j = n;
	while (i < j) {
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

void my_itoa(int n, char s[]) {
	int sign = (n >= 0) ? 1 : -1;
	n = (n >= 0) ? n : -n;
	int i = 0;
	while(n) {
		s[i++] = n % 10 + '0';
		n /= 10;
	}
	if(sign == -1) {
		s[i++] = '-';
	}
	s[i] = '\0';

	reverse(s, strlen(s)-1);
}

int main(void)
{
    char s[16];

    my_itoa(-10, s);
    printf("%s\n", s);

    return 0;
}


