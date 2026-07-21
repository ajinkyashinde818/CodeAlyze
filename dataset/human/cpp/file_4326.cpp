#include <bits/stdc++.h>
using namespace std;
int a[100500], b[100500];
int mid[100500], mid2[100500];
map<int, int> fa, ok;
int findfa(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = findfa(fa[x]);
}
int main()
{
	fa[-1] = -1;
	int n = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i), a[0] ^= a[i];
	for(int i = 1; i <= n; i++) scanf("%d", b + i), b[0] ^= b[i];
	for(int i = 0; i <= n; i++) mid[i] = a[i], mid2[i] = b[i];
	sort(mid, mid + n + 1), sort(mid2, mid2 + n + 1);
	for(int i = 0; i <= n; i++)
	{
		fa[a[i]] = a[i], fa[b[i]] = b[i];
		if(mid[i] != mid2[i])
		{
			puts("-1");
			return 0;
		}
	}
	int tot = 0;
	for(int i = 0; i <= n; i++)
	{
		if(a[i] != b[i])
		{
			if(i) tot++;
			fa[findfa(a[i])] = findfa(b[i]);
			ok[a[i]] = ok[b[i]] = 1;
		}
	}
	if(tot == 0) cout << 0 << endl;
	if(tot > 0)
	{
		ok[a[0]] = ok[b[0]] = 1;
		for(int i = 0; i <= n; i++)
			if(ok[a[i]] && a[i] == findfa(a[i]))
			{
				tot++;
				fa[a[i]] = -1;
			}
		cout << tot - 1 << endl;
	}
	return 0;
}
//ans=不同位置数+数字的轮换数（包括0）-1
