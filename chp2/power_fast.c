/**
 * Assume that both a and b are integer
 *
 * @reference : http://blog.csdn.net/zhizichina/article/details/7573342
 */

#include <stdio.h>

double fast_pow(int a, int b) {
	int r = 1, base = a;
	if(a == 0 || b == 0) {
		return 1;
	}
	else if(b > 0) {
		while(b != 0) {
			printf("a:%d, b:%d, base:%d, r:%d\n", a, b, base, r);
			if(b & 1) { // b is odd
				r *= base;
			}
			base *= base;
			b >>= 1;  // b %= 2
		}
		return r;
	}
	else {
		b *= -1;
		while(b != 0) {
			if(b & 1) {
				r *= base;
			}
			base *= base;
			b >>= 1;
		}
		return (double)1 / r;
	}
}

//int main() {
//	int a = 2;
//	int b = 10;
//	double p = fast_pow(a, b);
//
//	if(p - (int)p == 0) {
//		printf("power of %d^%d: %d\n", a, b, (int)p);
//	}
//	else{
//		printf("power of %d^%d: %.2lf\n", a, b, p);
//	}
//
//	return 0;
//}
