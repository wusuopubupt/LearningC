#include<string.h>
#include<stdio.h>

/*
	Description

	The C library function char *strtok(char *str, const char *delim) breaks string str into a series of tokens using the delimitrer delim.

	Declaration

	Following is the declaration for strtok() function.

	char *strtok(char *str, const char *delim)
	Parameters
	str -- The contents of this string are modified and broken into smaller strings (tokens).

	delim -- This is the C string containing the delimiters. These may vary from one call to another.

	Return Value
	This function returns a pointer to the last token found in string. A null pointer is returned if there are no tokens left to retrieve.
*/

/*
int main(void) {
	char s[16] = "a,b";
	char *p;
	p = strtok(s, ",");
	if (p)
		printf("s:%s, p:%s\n", s, p); //s:a, p:a

	p = strtok(NULL, ",");
	if (p)
		printf("s:%s, p:%s\n", s, p); //s:a, p:b

	return 0;
}
 */
