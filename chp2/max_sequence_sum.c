#include <stdio.h>

int max_subsequence_sum(const int*a, int n) {
    int this_sum, max_sum, j;
    this_sum = max_sum = 0;
    for(j = 0; j < n; j++) {
        this_sum += a[j];
        if(this_sum > max_sum) {
            max_sum = this_sum;
        }
        else if(this_sum < 0){
            this_sum = 0;
        }
    }
    return max_sum;
}

int main1() {
    int a[5] = {2, 4, -2, 6, -3};
    int max = max_subsequence_sum(a, 5);
    printf("max: %d\n", max);

    return 0;
}
