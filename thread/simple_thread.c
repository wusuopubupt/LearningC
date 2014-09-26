/*
 * @author : wusuopubupt
 * @desc   : test of c pthread lib
 * @date:  : 2014-09-26
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void print_msg(char *s) {
	printf("%s\n", s);
}

/* function pointer */
typedef void (*fp)(const void *);

int main() {
	pthread_t thread1, thread2;
	char *attr1 = "hello";
	char *attr2 = "world";

	pthread_create(&thread1, NULL, (fp)print_msg, (void *) attr1);
	pthread_join(thread1, NULL);
	printf("thread1 end\n");

	pthread_create(&thread2, NULL, (fp)print_msg, (void *) attr2);
	pthread_join(thread2, NULL);
	printf("thread2 end\n");

	pthread_exit(NULL);

	return 0;
}

