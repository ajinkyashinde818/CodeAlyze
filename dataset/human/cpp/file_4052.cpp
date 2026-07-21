/*░░░░░░░▄▄▄▀▀▀▄▄███▄
░░░░░▄▀▀░░░░░░░▐░▀██▌
░░░▄▀░░░░▄▄███░▌▀▀░▀█
░░▄█░░▄▀▀▒▒▒▒▒▄▐░░░░█▌
░▐█▀▄▀▄▄▄▄▀▀▀▀▌░░░░░▐█▄
░▌▄▄▀▀░░░░░░░░▌░░░░▄███████▄
░░░░░░░░░░░░░▐░░░░▐███████████▄
░░░░░le░░░░░░░▐░░░░▐█████████████▄
░░░░toucan░░░░░░▀▄░░░▐██████████████▄
░░░░░░has░░░░░░░░▀▄▄████████████████▄
░░░░░arrived░░░░░░░░░░░░█▀██████*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1007;
double x[MAXN], y[MAXN], r[MAXN];
double dist(int u, int v)
{
	double dx = x[u] - x[v], dy = y[u] - y[v];
	return max(0.0, sqrt(dx * dx + dy * dy) - r[u] - r[v]);
}
double d[MAXN];
bool used[MAXN];
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	double aa, bb, cc, dd;
	cin >> aa >> bb >> cc >> dd;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i] >> r[i];
	}
	x[n + 1] = aa, y[n + 1] = bb;
	x[n + 2] = cc, y[n + 2] = dd;
	for (int i = 1; i <= n + 2; i++)
	{
		d[i] = 1e30;
	}
	d[n + 1] = 0;
	n += 2;
	for (int i = 1; i <= n; i++)
	{
		int v = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!used[j] && (v == -1 || d[j] < d[v])) v = j;
		}
		used[v] = true;
		for (int j = 1; j <= n; j++)
		{
			d[j] = min(d[j], d[v] + dist(v, j));
		}
	}
	cout.precision(20);
	cout << fixed << d[n] << endl;
}
