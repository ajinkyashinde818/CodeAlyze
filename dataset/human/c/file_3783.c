#include <stdio.h> 


int main(void)
{
	long long int a, b, r, x, tmp;
	scanf("%lld", &a);
	scanf("%lld", &b);
	x = a * b;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	/* 最小公倍数を出力 */
	printf("%lld", x / b);

	return 0;


}
