#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
inline LL in()
{
    LL x = 0, flag = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') flag = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x * flag;
}
int n, m, ans, kind;
LL xsum, ori[MAXN], tar[MAXN], tot[MAXN];
int a[MAXN], b[MAXN], size[MAXN];
bool vis[MAXN];
int fa[MAXN];
int find(int x)
{
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}
void unite(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
	fa[fy] = fx;
    size[fx] += size[fy];
}
bool judge()
{
	map <LL, int> cnt;
    for (int i = 1; i <= n+1; i ++)
        cnt[ori[i]] ++;
    for (int i = 1; i <= n; i ++)
    {
        if (cnt[tar[i]] > 0)
	        cnt[tar[i]] --;
	    else 
	        return false;
    }
    return true;
}
void init()
{
	map <LL, int> id; 
    sort(tot + 1, tot + n + 2);
    id[tot[1]] = kind = 1;
    for (int i = 2; i <= n + 1; i ++)
    {
        if (tot[i] != tot[i-1]) kind ++;
        id[tot[i]] = kind;
    }
    for (int i = 1; i <= n+1; i ++)
    {
        a[i] = id[ori[i]];
        b[i] = id[tar[i]];
    }
}
int main()
{
	n = in();
	for (int i = 1; i <= n; i ++) 
    {
        tot[i] = ori[i] = in();
        ori[n + 1] ^= ori[i];
    }
    tot[n + 1] = ori[n + 1];
	for (int i = 1; i <= n; i ++) 
	{
		tar[i] = in();
		tar[n + 1] ^= tar[i];	
	}
    if (judge() == false) 
    {
        printf("-1");
        return 0;
    }
    init();
    for (int i = 1; i <= kind; i ++) fa[i] = i;
	for (int i = 1; i <= n + 1; i ++)
	{
		if (a[i] != b[i]) 
		{
			ans ++;
            size[a[i]] ++;
		}
	}
	for (int i = 1; i <= n + 1; i ++)
	{
		if (find(a[i]) == find(b[i])) continue;
		unite(a[i], b[i]);
	}
    for (int i = 1; i <= n + 1; i ++)
    {
        if (fa[a[i]] == a[i] && a[i] != b[i] && !vis[a[i]]) 
		{
			vis[a[i]] = true;
			ans ++;
		}
    }
	if (a[n+1] != b[n+1]) ans --;
	if (size[fa[a[n+1]]] > 1) ans --;
    cout << ans << endl;
	return 0;
}
