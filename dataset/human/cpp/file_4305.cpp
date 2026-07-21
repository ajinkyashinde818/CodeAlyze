#include <algorithm>
#include <cstdio>
#include <map>
std::map<int, int> app;
int a[100005], b[100005], fa[200005];
int getfa(int u)
{
	if (u == fa[u])
		return u;
	return fa[u] = getfa(fa[u]);
}
inline void unite(int u, int v)
{
	fa[getfa(u)] = getfa(v);
}
int main()
{
	// freopen("AGC016-D.in", "r", stdin);
	int n, cnt = 0, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		a[n] ^= a[i];
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", b + i);
		b[n] ^= b[i];
	}
	for (int i = 0; i < 200005; i++)
		fa[i] = i;
	for (int i = 0; i <= n; i++)
	{
		if (a[i] != b[i] || i == n)
		{
			if (!app.count(a[i]))
				app[a[i]] = cnt++;
			if (!app.count(b[i]))
				app[b[i]] = cnt++;
			unite(app[a[i]], app[b[i]]);
			ans++;
		}
	}
	ans--;
	for (int i = 0; i < cnt; i++)
		ans += i == fa[i];
	std::sort(a, a + n + 1);
	std::sort(b, b + n + 1);
	for (int i = 0; i <= n; i++)
	{
		if (a[i] != b[i])
		{
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", ans - 1);
	return 0;
}
