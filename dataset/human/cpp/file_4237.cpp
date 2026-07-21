#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N = 100010;
int n, a[N], b[N], aq[N], bq[N], fa[N], ans;
map<int, int> pos;

int Find(int u)
{
	if (fa[u] == u) return u;
	return fa[u] = Find(fa[u]);
}

void Merge(int x, int y)
{
	if (Find(x) == Find(y)) return;
	fa[Find(x)] = Find(y);
	ans--;
}

int main()
{
	scanf("%d", &n);
	a[n+1] = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		aq[i] = a[i];
		a[n+1] ^= a[i];
	}
	aq[n+1] = a[n+1];
	sort(aq+1, aq+n+2);
	for (int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
		bq[i] = b[i];
		b[n+1] ^= b[i];
	}
	bq[n+1] = b[n+1];
	sort(bq+1, bq+n+2);
	for (int i = 1; i <= n+1; i++)
		if (aq[i] != bq[i]){
			printf("-1");
			return 0;
		}
	ans = n*2;
	for (int i = 1; i <= n+1; i++) fa[i] = i;
	for (int i = 1; i <= n+1; i++){
		if (a[i] == b[i] && i != n+1)
			ans -= 2;
		else{
			if (pos.find(a[i]) != pos.end())
				Merge(pos[a[i]], i);
			else pos[a[i]] = i;
			if (pos.find(b[i]) != pos.end())
				Merge(pos[b[i]], i);
			else pos[b[i]] = i;
		}
	}
	printf("%d", ans);
	return 0;
}
