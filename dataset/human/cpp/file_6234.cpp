#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(ll u = 0, char c = getchar(), bool f = false) {
	for (;!isdigit(c); c = getchar()) f |= c == '-';
	for (; isdigit(c); c = getchar()) u = (u << 1) + (u << 3) + c - '0';
	return f ? -u : u;
}

const int maxn = 1e5 + 10;
ll x[maxn], v[maxn];
ll f[maxn][2], g[maxn][2];
int main() {
	int n = read(); ll c = read();
	for (int i = 1; i <= n; i++)
		x[i] = read(), v[i] = read();
		
	for (int i = 1; i <= n; i++) 
		f[i][0] = f[i - 1][0] - (x[i] - x[i - 1]) + v[i],
		f[i][1] = f[i - 1][1] - (x[i] - x[i - 1]) * 2 + v[i];
	
	for (int i = 1; i <= n; i++)
		f[i][0] = max(f[i][0], f[i - 1][0]),
		f[i][1] = max(f[i][1], f[i - 1][1]);
	
	x[n + 1] = c;
	
	for (int i = n; i >= 1; i--)
		g[i][0] = g[i + 1][0] - (x[i + 1] - x[i]) + v[i],
		g[i][1] = g[i + 1][1] - (x[i + 1] - x[i]) * 2 + v[i];
		
	for (int i = n; i >= 1; i--)
		g[i][0] = max(g[i][0], g[i + 1][0]),
		g[i][1] = max(g[i][1], g[i + 1][1]);
	
	ll ans = 0;
	for (int i = 0; i <= n; i++)
		ans = max(ans, max(f[i][0] + g[i + 1][1], f[i][1] + g[i + 1][0]));
	cout << ans << endl;
}
