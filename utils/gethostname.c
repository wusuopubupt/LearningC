/*
 * @desc   : Usage of gethostname()
 * @author : wusuopubupt
 * @date   : 2014-10-11
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	char name[65];
	snprintf(name, sizeof(name), "%d@", getpid());
	int offset = strlen(name);
	int new_buffer_len = sizeof(name) / sizeof(name[0]) - strlen(name);
	if (gethostname(name+offset, new_buffer_len) < 0) {
		perror("gethostname error\n");
	}
	printf("hostname = %s\n", name);

	return 0;
}
