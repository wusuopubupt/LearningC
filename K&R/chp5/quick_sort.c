/*
 * my blog which discussed quick sort:  http://blog.csdn.net/wusuopubupt/article/details/39347709
 *
 */
#include <stdio.h>

/* declare function pointer */
typedef int(*fp_operation)(int a, int b);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(int a, int b) {
    return (a-b);
}

void my_qsort1(int a[], int low, int high, fp_operation cmp) {
	int i, last;
	int pivot = a[low];
	if(low >= high) {
		return;
	}
	//swap(&a[low], &a[(low+high)/2]);
	last = low;
	i = low + 1;
	while(i < high) {
		if((*cmp)(a[i], pivot) < 0) {
			swap(&a[i], &a[++last]);
		}
		i++;
	}
	swap(&a[low], &a[last]);

	my_qsort1(a, low, last-1, cmp);
	my_qsort1(a, last+1, high, cmp);
}

void my_qsort(int arr[], int low, int high, fp_operation cmp) {
    if(low >= high) {
        return;
    }
    int pivot = arr[low];
    int mid;
    int i, j;
    i = j = low+1;
    while(j <= high) {
    	if((*cmp)(arr[j], pivot) < 0) {
    		swap(&arr[j], &arr[i]);
    		i++;
    	}
    	j++;
    }

    swap(&arr[low], &arr[i-1]);
    mid = i-1;

//    int k = 0;
//    printf("mid: %d\n", mid);
//    while(k < 16) {
//    	printf("%d ", arr[k]);
//    	k++;
//    }
//    printf("\n");

    my_qsort(arr, low, mid-1, cmp);
    my_qsort(arr, mid+1, high, cmp);
}

int main() {
    int arr[] = {2, 1, 7, 1, 5, 4, 9, 6, 1, 2, 4, 0, 5, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    my_qsort(arr, 0, n-1, (fp_operation)compare);

    int i = 0;
    while(i < n) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");

    return 0;
}
