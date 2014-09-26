/*
 * @author	: wusuopubupt
 * @desc	: practice of thread array
 * @date 	: 2014-09-26
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *tid) {
    printf("Hello, world! It's me, threadid: %u!\n", (unsigned int)pthread_self());
    pthread_exit(NULL);
}

typedef void *(*fp)(void *);

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t = 0; t < NUM_THREADS; t++) {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, (fp)print_hello, (void *)t);
        if(rc) {
            printf("Error, return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    pthread_exit(NULL);
}
