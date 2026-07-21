#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>

using namespace std;

const int MAXN = 100000 + 1000;

int n, tot, ans = 0;
int a[MAXN], b[MAXN];
vector<int> edg[MAXN];

void discrete()
{
	static map<int, int> d;
	for(int i = 0; i <= n; i++)
		a[i] = (d[a[i]] ? d[a[i]] : d[a[i]] = ++tot);
	for(int i = 0; i <= n; i++)
		b[i] = (d[b[i]] ? d[b[i]] : d[b[i]] = ++tot);
}

bool check_no()
{
	static int arr1[MAXN], arr2[MAXN];
	for(int i = 0; i <= n; i++)
		arr1[i] = a[i], arr2[i] = b[i];
	sort(arr1, arr1 + n + 1);
	sort(arr2, arr2 + n + 1);
	for(int i = 0; i <= n; i++)
		if(arr1[i] != arr2[i])
			return true;
	return false;
}

bool vis[MAXN];
int dfs(int x)
{
	int ret = 1;
	vis[x] = true;
	for(int i = 0; i < edg[x].size(); i++)
		if(!vis[edg[x][i]])
			ret += dfs(edg[x][i]);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++)
		a[0] ^= a[i], b[0] ^= b[i];

	if(check_no())
	{
		cout << -1 << endl;
		return 0;
	}
	discrete();
	for(int i = 0; i <= n; i++)
		if(a[i] != b[i])
		{
			ans++;
			edg[a[i]].push_back(b[i]);
			edg[b[i]].push_back(a[i]);
		}
	if(!ans)
	{
		cout << 0 << endl;
		return 0;
	}
	if(a[0] != b[0])
		ans = ans - 1;
	for(int i = 1; i <= n + 1; i++)
		if(!vis[i])
			if(dfs(i) > 1 || (i == a[0] && a[0] == b[0]))
				ans++;
	ans = ans - 1;
	cout << ans << endl;


	return 0;
}
