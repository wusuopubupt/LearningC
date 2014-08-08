#include <stdio.h>
int josephus1(int n, int m) {
	if(n == 1) {
		return 0;
	}
	else {
		return (josephus1(n-1, m) + m) % n;
	}
}

//#include <stdio.h>
//int main() {
//	int n, m, i, result;
//	while (scanf("%d", &n) == 1) {
//		if (!n) {
//			break;
//		}
//		scanf("%d", &m);
//		result = 0;
//		for (i = 2; i <= n; i++) {
//			result = (result + m) % i;
//		}
//		printf("%d\n", result + 1);
//	}
//	return 0;
//}

//int main() {
//	int n, m;
//	while (scanf("%d", &n) == 1) {
//		if (!n) {
//			break;
//		}
//		scanf("%d", &m);
//		int result = josephus(n, m);
//		printf("%d\n", result+1);
//	}
//	return 0;
//}
