#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 7;
char s[N];
int t[N];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < 2 * n; i++) {
		t[i] = s[i] == 'B' ? 1 : 0;
		if (i % 2 == 0) t[i] ^= 1;
	}
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++)
		cnt += t[i];
	if (cnt != n) {
		puts("0");
		return 0;
	}
	int ans = 1, temp = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (t[i] == 0) {
			temp++;
		} else {
			ans = 1LL * ans * temp % MOD;
			temp--;
		}
		if (i < n) ans = 1LL * (i + 1) * ans % MOD;
	}
	printf("%d\n", ans);
	return 0;
}
