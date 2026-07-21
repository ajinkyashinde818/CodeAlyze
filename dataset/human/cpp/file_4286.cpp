#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100000;
const int MaxNV = MaxN * 2 + 2;

int n;
int a[MaxN + 1], b[MaxN + 1];
int c[MaxN + 1], d[MaxN + 1];

int ufs[MaxN + 1];

int nV = 0;
map<int, int> id;

inline void add(const int &v)
{
	if (id.find(v) == id.end())
	{
		id.emplace(v, ++nV);
		ufs[nV] = nV;
	}
}

int ufs_find(const int &u)
{
	return ufs[u] == u ? u : ufs[u] = ufs_find(ufs[u]);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		a[i] = getint(), a[0] ^= a[i];
	for (int i = 1; i <= n; ++i)
		b[i] = getint(), b[0] ^= b[i];

	for (int i = 0; i <= n; ++i)
		c[i] = a[i], d[i] = b[i];
	sort(c, c + n + 1);
	sort(d, d + n + 1);

	for (int i = 0; i <= n; ++i)
		if (c[i] != d[i])
		{
			cout << -1 << endl;
			return 0;
		}

	int res = 0;
	for (int i = 0; i <= n; ++i)
		if (a[i] != b[i] || !i)
		{
			res += i > 0;
			add(a[i]), add(b[i]);
		}

	if (res == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i <= n; ++i)
		if (a[i] != b[i])
		{
			int u = ufs_find(id[a[i]]);
			int v = ufs_find(id[b[i]]);
			ufs[u] = v;
		}

	for (int i = 1; i <= nV; ++i)
		res += ufs[i] == i;

	cout << res - 1 << endl;

	return 0;
}
