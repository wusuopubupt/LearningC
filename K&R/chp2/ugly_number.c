#include<stdio.h>
 
static int min(int a, int b, int c) {
    int min = a < b ? a : b;
    return (min < c ? min : c);
}
 
/*
int main() {
    int n;
 
    while (scanf("%d", &n) != EOF) {
        int i, i2 = 0, i3 = 0, i5 = 0;
        int ugly_num[n];
        ugly_num[0] = 1;
        for (i = 1; i < n; i++) {
            ugly_num[i] = min(ugly_num[i2]*2, ugly_num[i3]*3, ugly_num[i5]*5);
            if (ugly_num[i] == ugly_num[i2]*2) {
                i2++;
            }
            if (ugly_num[i] == ugly_num[i3]*3) {
                i3++;
            }
            if (ugly_num[i] == ugly_num[i5]*5) {
                i5++;
            }
            //printf("i:%d, i2:%d, i3:%d, i5:%d, ugly_num[%d]:%d\n", i,i2, i3, i5, i, ugly_num[i]);
        }
        printf("%d\n", ugly_num[n-1]);
    }
    return 0;
}

*/

/**************************************************************
    Problem: 1214
    User: wusuopuBUPT
    Language: C
    Result: Accepted
    Time:20 ms
    Memory:912 kb
****************************************************************/
