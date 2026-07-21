#include <stdio.h>
#include <stdbool.h>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
typedef long long ll;

const ll inf = (1ll << 60ll);

ll d, g;
ll p[11], c[11];
ll ans = inf;
bool used[11];

ll dfs(ll points, ll i);

int main()
{
	scanf("%lld %lld", &d, &g);
	for (ll i = 1; i <= d; i++) {
		scanf("%lld %lld", &p[i], &c[i]);
	}

	printf("%lld\n", dfs(0, 1));

	return 0;
}

ll dfs(ll points, ll i)
{
	if (points >= g) { 
		return 0;
	}

	if (i > d) {

		ll j = d;

		while (used[j] && j > 0) {
			j--;
		}

		//(g - points) / (100 * j) + ((g - points) % (100 * j) ? 1 : 0)
		if ((g - points) / (100 * j) + ((g - points) % (100 * j) ? 1 : 0) < p[j]) {
			return (g - points) / (100 * j) + ((g - points) % (100 * j) ? 1 : 0);
		} else {
			return inf;
		}
	}

	ll ret_val;

	used[i] = true;
	ret_val = dfs(points + (100 * i) * p[i] + c[i], i + 1) + p[i];

	used[i] = false;
	ret_val = min(ret_val, dfs(points, i + 1));

	return ret_val;
}
