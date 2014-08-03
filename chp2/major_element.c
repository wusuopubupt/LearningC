/**
 * @author : wusuopubupt
 * @desc   : get major element in O(n) time complexity
 * @refer  : http://blog.csdn.net/niushuai666/article/details/7335210
 * 			 http://site.douban.com/196781/widget/forum/12602268/discussion/51897495/
 */
#include <stdio.h>

int find_major(const int *a, int n) {
	printf("\n-------\n%d\n-------\n", n);
	int i = 0, j = 0;
	int b[n/2];

	while(i < n) {
		printf("%d ", a[i]);
		i++;
	}
	putchar('\n');

	i = 0;
	if(n == 0) {
		return -1;
	}
	else if(n == 1) {
		return a[0];
	}
	else if(n > 1){
		while(i < n) {
			printf("i:%d, j:%d, a[i]:%d\n", i, j, a[i]);
			if(i == n-1) { // n is  odd
				b[j++] = a[i];
			}
			else if(a[i] == a[i+1]) {
				b[j++] = a[i];
			}
			i += 2;
		}
	}

	return find_major(b, j);
}

//int main() {
//	int a[9] = {3, 5, 2, 4, 2, 5, 2, 2, 2};
//
//	int i = 0;
//	int n = sizeof(a)/sizeof(a[0]);
//	int count = 0;
//
//	int find = find_major(a, n);
//	while(i < n) {
//		if(find == a[i]) {
//			count++;
//		}
//		i++;
//	}
//	if(count > n/2) {
//		printf("major element: %d\n", find);
//	}
//	else {
//		printf("no major element\n");
//	}
//
//	return 0;
//}
