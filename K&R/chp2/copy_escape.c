#include <stdio.h>
#include <string.h>
 
void escape(char s[], char t[])
{
    int i = 0, j = 0;
    while (t[i] != EOF) {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
        ++i;
    }
    s[j] = EOF;
}
 
int main(void)
{
    char s[50];
    char t[20] = "just \t for a test\n\n !";
    escape(s, t);
    printf("%s\n", s);
    return 0;
}
