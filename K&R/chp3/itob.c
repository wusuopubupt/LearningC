/*
 * Write the function itob(n,s,b) that converts the integer n into a
 * base b character representation in the string s. In particular,
 * itob(n,s,16) formats n as a hexadecimal integer in s.
 */
#include <stdio.h>
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

/*
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
*/

void my_itob(int n, char s[], int step) {
	int sign = (n >= 0) ? 1 : -1;
	n = (n >= 0) ? n : -n;
	char *symbols = "0123456789ABCDEF";
	int i = 0;
	while(n) {
		//s[i++] = n % step + '0'; can not deal with hex
		s[i++] = *(symbols + n % step);
		n /= step;
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

    my_itob(-10, s, 16);
    printf("%s\n", s);

    return 0;
}


