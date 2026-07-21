#include <stdio.h>
long long n;
int a, x, y;
int main() {
	scanf("%lld", &n);
	for (long long i = 2; i < 1000000; i++) {
		while (!(n % i)) {
			a++;
			n /= i;
		}
		x = 1;
		while (a >= x) {
			a -= x;
			x++;
		}
		y += x - 1;
		a = 0;
	}
	if (n != 1)y++;
	printf("%d\n", y);
}
