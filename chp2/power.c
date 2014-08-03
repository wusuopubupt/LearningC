/**
 * Assume that both a and b are integer
 *
 */

#include <stdio.h>

double my_pow(int a, int b) {
	int r = 1;
	if(a == 0 || b == 0) {
		return 1;
	}
	else if(b > 0) {
		while(b--) {
			printf("a:%d, b:%d\n", a, b);
			r *= a;
		}
		return r;
	}
	else {
		b *= -1;
		while(b--) {
			r *= a;
		}
		return (double)1 / r;
	}
}

//int main() {
//	int a = -2;
//	int b = 2;
//	double p = my_pow(a, b);
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
