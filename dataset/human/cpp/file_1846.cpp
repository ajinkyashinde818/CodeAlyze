#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200005;

int n, m;
int req[N];
int num[N];
bool vis[N];

signed main(void)
{
	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
		cin >> req[i];

	memset(vis, 0, sizeof(vis));

	int tot = 0, p = 1;

	for (int i = m; i >= 1; --i)
		if (!vis[req[i]])
		{
			vis[req[i]] = true;
			num[++tot] = req[i];
		}

	while (tot < n)
	{
		while (vis[p])++p;
		num[++tot] = p++;
	}

	for (int i = 1; i <= n; ++i)
		cout << num[i] << endl;
}
