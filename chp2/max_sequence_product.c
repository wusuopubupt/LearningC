#include <stdio.h>

int max(int a, int b, int c){
    int max;
    max = a > b ? a : b;
    max = max > c ? max : c;
    return max;
}

int min(int a, int b, int c) {
    int min;
    min = a < b ? a : b;
    min = min < c ? min : c;
    return min;
}

int max_sequence_product(const int *a, int n) {
    int pos_max, neg_max, max_product;
    max_product = a[0] * a[1];
    pos_max = neg_max = a[0];

    int i = 1;
    while(i < n) {
        int pos_max_tem = pos_max;
        pos_max = max(a[i], a[i]*pos_max, a[i]*neg_max); // pos_max changed !!!
        neg_max = min(a[i], a[i]*pos_max_tem, a[i]*neg_max);

        if(pos_max > max_product) {
            max_product = pos_max;
        }

        printf("i:%d, post:%d, neg:%d, max:%d\n", i, pos_max, neg_max, max_product);

        i++;
    }

    return max_product;
}

//int main() {
//    int a[6] = {-3, 4, 2, -5, -2, 4};
//    int product = max_sequence_product(a, 6);
//    printf("product: %d\n", product);
//
//    return 0;
//}
