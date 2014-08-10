#include<stdio.h>
#define N 100005

int stack1[N], stack2[N];

/*
int main() {
    int n, top1, top2, v;
    char s[10];
    while (scanf("%d", &n) != EOF) {
        top1 = 0, top2 = 0;
        while (n--) {
            scanf("%s", s);
            if (s[1] == 'U') {
                scanf("%d", &v);
                stack1[top1++] = v;
            }
            else {
                if (top2 == 0) {
                    while (top1) {
                        stack2[top2++] = stack1[--top1];
                    }
                }
                if (top2) {
                    printf("%d\n", stack2[--top2]);
                }
                else {
                    printf("-1\n");
                }
            }
        }
    }
    return 0;
}
*/
