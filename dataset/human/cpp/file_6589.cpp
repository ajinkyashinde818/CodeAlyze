#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

char s[200010];

int main() {
	int n; scanf("%d", &n), n += n;
	scanf("%s", s);
	if (s[0] == 'W' || s[n - 1] == 'W') {
		printf("0\n");
		return 0;
	}
	long long ans = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x = s[i] == 'W' ? 0 : 1;
		if ((x ^ 1 ^ (cnt & 1))) {
			ans = ans * cnt % mod, cnt--;
			if (cnt < 0) {
				printf("0\n");
				return 0;
			}
		}
		else cnt++;
	}
	for (int i = 1; i <= n / 2; i++) {
		ans = ans * i % mod;
	}
	if (cnt != 0) printf("0\n");
	else printf("%lld\n", ans);
	return 0;
}
