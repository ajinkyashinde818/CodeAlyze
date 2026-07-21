#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 200000 + 5, mod = 1000000007;
inline int add (int u, int v) { return u + v >= mod ? u + v - mod : u + v; }
inline int mns (int u, int v) { return u - v < 0 ? u - v + mod : u - v; }
inline int mul (int u, int v) { return 1LL * u * v % mod; }
inline int qpow (int u, int v) {
	int tot = 1, base = u % mod;
	while (v) {
		if (v & 1) tot = mul (tot, base);
		base = mul (base, base);
		v >>= 1;
	}
	return tot;
}

char info[N];
int n, cnt[N];

int main () {
	scanf ("%d%*c", &n);
	scanf ("%s", info + 1);
	n = strlen (info + 1);
	for (int i = 1; i <= n; ++i) {
		cnt[i] = info[i] == 'B';
	}
	int lef = 0, ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i]) {
			if (lef % 2 == 0) {
				if (n - i < lef + 1) { puts ("0\n"); return 0; }
				else {
					lef++;
					continue;
				}
			}
			else {
				if (!lef) { puts ("0\n"); return 0; }
				ans = mul (ans, lef);
				lef--;
				continue;
			}
		}
		else {
			if (lef % 2 == 0 ) {
				if (!lef) { puts ("0\n"); return 0; }
				ans = mul (ans, lef);
				lef--;
				continue;
			}
			else {
				if (n - i < lef + 1) { puts ("0\n"); return 0; }
				lef++;
				continue;
			}
		}
	}
	for (int i = 2; i <= n / 2; ++i) ans = mul (ans, i);
	printf ("%d\n", ans);
	return 0;
}
