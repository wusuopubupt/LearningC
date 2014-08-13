#include<stdio.h>
#include<stdlib.h>

int num[100001];

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int i, n, m;
    while(scanf("%d", &n) != EOF) {
        int count = 0;
        for(i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }

        qsort(num, n, sizeof(int), cmp);

        int mid = num[n/2]; /*if there is the number x that occured > n/2 times, num[n/2] must be x*/
        for(i = 0; i < n; i++) {
            if(num[i] == mid) {
                count++;
            }
        }
        if(count > n/2) {
            printf("%d\n", mid);
        }
        else {
            printf("-1\n");
        }
    }
    return 0;
}
/**************************************************************
    Problem: 1370
    User: wusuopuBUPT
    Language: C
    Result: Accepted
    Time:70 ms
    Memory:1696 kb
****************************************************************/
