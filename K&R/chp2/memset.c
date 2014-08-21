/*
 Description

 The C library function void *memset(void *str, int c, size_t n)
 copies the character c (an unsigned char) to the first n characters of the string
 pointed to by the argument str.
 */

#include <stdio.h>
#include <string.h>

int main() {
	char s[13] = "I love China";
	printf("%s\n", s);

	memset(s, 'x', 4);
	printf("%s\n", s);

	return 0;
}
