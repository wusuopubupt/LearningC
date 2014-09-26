/*
 * @author	: wusuopubupt
 * @desc 	: practice of thread with metux lock
 * @date:	: 2014-09-26
 * @refer	: http://www.cnblogs.com/fuyunbiyi/p/3475602.html
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void increase_num(void);
void increase_num_with_lock();

int sharedi = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(){
    int ret;
    pthread_t thrd1, thrd2, thrd3;

//    ret = pthread_create(&thrd1, NULL, (void *)increase_num, NULL);
//    ret = pthread_create(&thrd2, NULL, (void *)increase_num, NULL);
//    ret = pthread_create(&thrd3, NULL, (void *)increase_num, NULL);

    ret = pthread_create(&thrd1, NULL, (void *)increase_num_with_lock, NULL);
    ret = pthread_create(&thrd2, NULL, (void *)increase_num_with_lock, NULL);
    ret = pthread_create(&thrd3, NULL, (void *)increase_num_with_lock, NULL);

    pthread_join(thrd1, NULL);
    pthread_join(thrd2, NULL);
    pthread_join(thrd3, NULL);

    printf("sharedi = %d\n", sharedi);

    return 0;
}

/* thread with mutex lock, sharedi will be 300000*/
void increase_num_with_lock(void) {
    long i,tmp;
    for(i=0; i<=100000; i++) {
        if (pthread_mutex_lock(&mutex) != 0) {
           perror("pthread_mutex_lock");
           exit(EXIT_FAILURE);
        }
        sharedi++;
        if (pthread_mutex_unlock(&mutex) != 0) {
            perror("pthread_mutex_unlock");
            exit(EXIT_FAILURE);
        }
    }
}

/* thread without lock, sharedi will be less than 300000 */
void increse_num(void) {
    long i,tmp;
    for(i=0; i<=100000; i++) {
        sharedi++;
    }
}
