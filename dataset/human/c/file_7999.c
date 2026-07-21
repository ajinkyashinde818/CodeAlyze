#include <stdio.h>
#include <stdlib.h>

long long div_mod(long long x, long long y, long long z)
{
	if (x % y == 0) return x / y;
	else return (div_mod((1 + x / y) * y - x, (z % y), y) * z + x) / y;
}

int main()
{
	int X, Y;
	scanf("%d %d", &X, &Y);
	
	if ((X + Y) % 3 != 0 || X * 2 < Y || Y * 2 < X) {
		printf("0\n");
		fflush(stdout);
		return 0;
	}
	
	long long i, total = (X + Y) / 3, left = (X * 2 - Y) / 3, right = total - left, min = (left < right)? left: right, ans = 1;
	for (i = 0; i < min; i++) ans = ans * (total - i) % 1000000007;
	for (i = 2; i <= min; i++) ans = div_mod(ans, i, 1000000007);
	
	printf("%lld\n", ans);
	fflush(stdout);
	return 0;
}
