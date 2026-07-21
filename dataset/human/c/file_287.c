#include <stdio.h>
#include <stdlib.h>
#define max(X, Y) ((X) > (Y) ? (X) : (Y))
typedef long long ll;

ll n;
ll a[100005];
ll ans;
ll sum;
int f;

int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);

		sum += llabs(a[i]);

		if (a[i] < 0) {
			f++;
			f %= 2;
		}
	}

	if (f) {
		for (int i = 1; i <= n; i++) {
			ans = max(ans, sum - (2 * llabs(a[i])));
		}
	}
	else {
		ans = sum;
	}

	printf("%lld\n", ans);
}
