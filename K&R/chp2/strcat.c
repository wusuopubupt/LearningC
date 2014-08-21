/*
 Description

 The C library function char *strcat(char *dest, const char *src)
 appends the string pointed to by src to the end of the string pointed to by dest.
 */

#include <stdio.h>
#include <string.h>

int main() {
	char src[50], dest[50];

	strcpy(src, "This is source");
	strcpy(dest, "This is destination");

	strcat(dest, src);

	printf("Final destination string : |%s|", dest); //Final destination string : |This is destinationThis is source|

	return (0);
}

