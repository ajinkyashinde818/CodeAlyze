#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int MAXN = 100005;

ll f[MAXN][2];

int a[MAXN];

int n;

template<typename T> inline bool updmax(T &a, T b) { return (a < b ? a = b, 1 : 0); }

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 2; j++)
			f[i][j] = -INF;
	f[2][0] = a[1] + a[2];
	f[2][1] = -(a[1] + a[2]);
	for (int i = 2; i < n; i++)
	{
		updmax(f[i + 1][0], f[i][0] + a[i + 1]);
		updmax(f[i + 1][0], f[i][1] + a[i + 1]);
		updmax(f[i + 1][1], f[i][0] - 2ll * a[i] - a[i + 1]);
		updmax(f[i + 1][1], f[i][1] + 2ll * a[i] - a[i + 1]);
	}
	ll res = 0;
	updmax(res, f[n][0]);
	updmax(res, f[n][1]);
	cout << res << endl;
	return 0;	
}
