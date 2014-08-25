#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_atoi(const char *str);

int main() {
	char *s = "-10";
	int n = my_atoi(s);

	printf("my_atoi result: %d\n", n);

	return 0;
}

int my_atoi(const char *str) {
	int result = 0;
	int signal = 1;
	int step = 10;

	if (!str)
		return 0;
	if (!str[0])
		return 0;

	if (*str == '-') {
		signal = -1;
		str++;
	}
	else if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X')) {
		step = 16;
		str += 2;
	}

	if (step == 10) {
		while (*str >= '0' && *str <= '9') {
			result = result * 10 + (*str - '0');
			str++;
		}
	}
	else if (step == 16) {
		while (*str) {
			if (*str >= '0' && *str <= '9') {
				result = result * 16 + (*str - '0');
			}
			else if (*str >= 'a' && *str <= 'f') {
				result = result * 16 + (*str - 'a' + 10);
			}
			else if (*str >= 'A' && *str <= 'f') {
				result = result * 16 + (*str - 'A' + 10);
			}

			str++;
		}
	}

	return signal * result;
}
