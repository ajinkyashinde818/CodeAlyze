#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxL = 1e18;
const int maxm = 1e5 + 10;
int n, tot;
ll L, ans;
map<ll, ll> sg;
char s[maxm];
int ch[maxm][2];
inline ll lowbit(ll x) { return x & (-x);}
inline int newnode(int& now)
{ 
	return now ? now : now = ++tot;
}
void insert(int& root)
{
	int now = newnode(root);
	int m = strlen(s + 1);
	for(int i = 1; i <= m; ++i)
		now = newnode(ch[now][s[i] - '0']);
}
void dfs(int x, int dep)
{
	if(!x)
	{
		ans ^= lowbit(L - dep + 1); //sg
		return;
	}
	if(!ch[x][0] && !ch[x][1]) return;
	dfs(ch[x][0], dep + 1);
	dfs(ch[x][1], dep + 1);
}
int main()
{
	int root = 0;
	scanf("%d%lld", &n, &L);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", s + 1);
		insert(root);
	}
	dfs(root, 0);
	if(ans) puts("Alice");
	else puts("Bob");
	return 0;
}
/*
void pre()
{
	sg[0] = 0;
	for(ll i = 1; i <= maxL; i <<= 1)
	{
		set<ll> mex;
		for(ll j = 1; j <= i; j <<= 1)
		{
			ll x = i - j, cur = 0;
			for(ll k = 1; k <= x; k <<= 1)
				if(x & k)
					cur ^= sg[k];
			mex.insert(cur);
		}
		ll ret = 0;
		while(mex.find(ret) != mex.end())
			++ret;
		sg[i] = ret;
		//cout << i << ' ' << sg[i] << ' ' << lowbit(int(log2(i))) << endl;
	}
}
*/
/*
2 3
0
10
*/
