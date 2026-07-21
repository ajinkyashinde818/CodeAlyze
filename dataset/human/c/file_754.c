#include <stdio.h>
#define MOD ((long long)(1e9) + 7)
typedef long long ll;

ll n;
char str[100005];
ll count[30];
ll ans;

int main()
{
	scanf("%lld", &n);
	scanf("%s", str);

	for (ll i = 0; i < n; i++) {
		count[str[i] - 'a']++;
	}

	ans = 1;
	for (ll i = 0; i < 30; i++) {
		if (count[i]) {
			ans = ans * (count[i] + 1);
		}
		ans = ans % MOD;
	}
	ans--;
	ans = ans % MOD;

	printf("%lld\n", ans);

	return 0;
}
