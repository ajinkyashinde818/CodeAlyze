#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
using namespace std;

const int maxn = 100010 * 2;

int a[maxn], b[maxn];
int father[maxn];
map<int,int> mapp;
int cnt[maxn];
multiset<int> s;
int n;
set<int> all;

bool check_same()
{
	for (int i=1;i<=n;i++) s.insert(a[i]);
	for (int i=1;i<=n;i++)
	{
		if (s.count(b[i]) == 0) return false;
		multiset<int>::iterator iter = s.lower_bound(b[i]);
		s.erase(iter);
	}
	return true;
}

int find(int x)
{
	if (father[x] != x) father[x] = find(father[x]);
	return father[x];
}

void link(int u, int v)
{
	int fx = find(u), fy = find(v);
	if (fx != fy) father[fx] = fy;
}
	
int main()
{
	//freopen("D.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]), a[n+1] ^= a[i];
	for (int i=1;i<=n;i++) scanf("%d",&b[i]), b[n+1] ^= b[i];
	n++;
	if (!check_same())
	{
		puts("-1");
		return 0;
	}

	for (int i=1;i<=n;i++) father[i] = i;
	for (int i=1;i<=n;i++) mapp[a[i]] = i;
	int edge = 0;
	for (int i=1;i<n;i++)
	{
		if (a[i] != b[i]) 
		{
			link(mapp[a[i]],mapp[b[i]]);
			edge++;
		}
	}
	for (int i=1;i<n;i++) 
		if (a[i] != b[i]) all.insert(find(mapp[a[i]])), all.insert(find(mapp[b[i]]));
	int cc = (int)all.size();
	if (all.count(find(mapp[a[n]])) == 0) cc++;
	if (all.count(find(mapp[b[n]])) == 0 && a[n] != b[n]) cc++;
	printf("%d\n",edge + cc - 1);
	return 0;
}
