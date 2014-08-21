/*
	Description
	The C library function char *strncpy(char *dest, const char *src, size_t n)
	copies up to n characters from the string pointed to by src to dest.
	In the case where the length of src is less than that of n,
	the remainder of dest will be padded with null bytes
*/

#include <stdio.h>
#include <string.h>

int main()
{
   char src[40];
   char dest[12];

   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.com");
   strncpy(dest, src, 10);

   printf("Final copied string : %s\n", dest); //Final copied string : This is tu

   return(0);
}


