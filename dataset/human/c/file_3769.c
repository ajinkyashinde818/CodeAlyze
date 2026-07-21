#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define pai 3.1415926535


int main(void) {
	long long int A, B;
	scanf("%lld%lld", &A, &B);
	long long int tmp, r;
	long long int x = A * B;
	if (A < B) {
		tmp = A;
		A = B;
		B = tmp;
	}

	/* ユークリッドの互除法 */
	r = A % B;
	while (r != 0) {
		A = B;
		B = r;
		r = A %B;
	}

	/* 最小公倍数を出力 */
	printf("%lld\n", x / B);


	return 0;


}
