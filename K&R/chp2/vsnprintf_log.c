#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

static const int MAX_LOG_LENGTH = 4*1024;

static void print_log(const char * format, ...)
{
    va_list args;
    va_start(args, format);

    char buf[MAX_LOG_LENGTH];

    vsnprintf(buf, MAX_LOG_LENGTH - 3, format, args);
    strcat(buf, "\n");
    fprintf(stdout, "log: %s", buf);
    fflush(stdout);
    va_end(args);
}


int main() {
	print_log("%d %s", 111000, "test");

	return 0;
}
