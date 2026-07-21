#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

char s[N];
int a[N], sum[N];
int n, m;

const int mod = 1e9 + 7;

int main() {
	scanf("%d %s", &n, s);
    m = strlen(s);
    int cur = 0;
    for (int i = m-1; i >= 0; i --) {
        int t = (s[i] == 'B');
        if (cur ^ t) a[i] = -1;
        else a[i] = 1;
        cur ^= 1;
    }
    sum[0] = a[0];
    bool flag = 0;
    flag |= (sum[0] < 0);
    for (int i = 1; i < m; i ++) {
		sum[i] = sum[i-1] + a[i];
        flag |= (sum[i] < 0);
    }
    int ans = 1, g = 0;
	for (int i = 0; i < m; i ++) {
		if (a[i] == 1) {
			g ++;
            continue;
		}
        if (g == 0) {ans = 0; break;}
        ans = 1ll * ans * g % mod;
        g --;
	}
    if (g) ans = 0;
    if (ans) {
        for (int i = 1; i <= n; i ++) ans = 1ll * ans * i % mod;
    }
    printf("%d\n", ans);
	return 0;
}
