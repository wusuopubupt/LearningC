#include <stdio.h>
#include <stdlib.h>

void func(int **a) {
    *a = (int *)malloc(sizeof(int));
}
int main() {
    int *p = NULL;
    func(&p);
    *p = 6;
    printf("%d\n", *p);
    return 0;
}
