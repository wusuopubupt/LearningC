#include <stdio.h>

int min_subsequence_sum(const int *a, int n) {
    int i = 1, min_sum, this_sum;
    min_sum = this_sum = a[0] + a[1];
    while(i < n) {
        if(i > 1){
            this_sum += a[i];
        }
        if(this_sum < min_sum) {
            min_sum = this_sum;
        }
        else if(this_sum > a[i]) {
            this_sum = a[i];
        }
        printf("i:%d, this_sum:%d, min_sum:%d\n", i, this_sum, min_sum);

        i++;
    }

    return min_sum;
}

int main() {
    int a[5] = {-1, 5, 2, 3, 4};
    int min = min_subsequence_sum(a, 5);
    printf("min:%d\n", min);

    return 0;
}
