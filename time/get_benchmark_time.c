/*
 * @author  : wusuopubupt
 * @desc	: function get_time() can be used in benchmark
 * @date	: 2014-09-26
 */
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

double get_millisecond() {
	struct timeval t;
	struct timezone tzp;
	gettimeofday(&t, &tzp);
	return t.tv_sec*1000 + t.tv_usec/1000; // return millisecond
}

double get_second() {
	struct timeval t;
	struct timezone tzp;
	gettimeofday(&t, &tzp);
	return t.tv_sec + t.tv_usec * 1e-6; // return second + microsecond/1000000
}

int main() {
	double start_time = get_second();
	increase_num();
	double end_time = get_second();
	printf("%f, start: %f, end:%f\n", end_time - start_time, start_time, end_time);

	return 0;
}

void increase_num(void) {
	long i;
	for (i = 0; i < 10000000; i++) {
		i++;
	}
}
