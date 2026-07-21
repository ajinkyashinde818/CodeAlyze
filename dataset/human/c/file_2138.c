// ABC 148-E
// 2019.12.22 bal4u

#include <stdio.h>

typedef long long ll;

int main()
{
	ll N, n5, ans = 0;
	
	scanf("%lld", &N);
	if ((N & 1) == 0) {
		N /= 2, n5 = 5;
		while (N >= n5) {
			ans += N/n5;
			n5 *= 5;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
