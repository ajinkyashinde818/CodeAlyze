#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
typedef long long ll;

int main() {
	int tmp, neg = 0, m = int(1e9) + 7, n;
	ll res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &tmp);
		if (tmp < 0) {
			tmp = -tmp;
			neg++;
		}
		m = min(m, tmp);
		res = res + 1LL * tmp;
	}
	if (neg % 2 == 0) cout << res;
	else cout << res - m * 2;
	return 0;
}
