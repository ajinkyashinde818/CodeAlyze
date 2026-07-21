#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void) {
	long long n,ans = 0;
	long long div = 1;
	scanf("%lld", &n);
	if (n % 2) printf("%d", 0);
	else {
		long long a = n / 2;
		while (a / div) {
			div *= 5;
			ans += a / div;
		}
		printf("%lld", ans);
	}
	return 0;
}
