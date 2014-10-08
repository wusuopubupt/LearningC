/*
 * Reference : https://github.com/madeye/shadowsocks-libev/blob/master/src/utils.h
 */
#include <stdio.h>
#include <time.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

#define use_syslog 0
#define TIME_FORMAT "%Y-%m-%d %H:%I:%S"

#define LOG(format, ...) do {\
    if (use_syslog) {\
        syslog(LOG_ERR, format, ##__VA_ARGS__);\
    } else {\
        time_t now = time(NULL);\
        char timestr[20];\
        strftime(timestr, 20, TIME_FORMAT, localtime(&now));\
        fprintf(stderr, "\e[01;35m %s ERROR: \e[0m" format "\n", timestr, ##__VA_ARGS__);\
    }}\
while(0)

void ERROR(const char *s)
{
    char *msg = strerror(errno);
    LOG("%s: %s", s, msg);
}

int main() {
	LOG("undefined param %s", "sss");

	return 0;
}
