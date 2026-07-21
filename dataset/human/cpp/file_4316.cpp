#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int a[101010],b[101010];
bool flag;
int n,s,num,ans;
int dog[202020],fa[202020];
bool br[202020];
int find(int x)
{
	if (fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	x=find(x); y=find(y);
	if (x!=y) fa[x]=y;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]),s^=a[i];
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&b[i]);
		if (s==b[i]) flag=1;
	}
	for (int i=1;i<=n;++i)
	{
		if (!mp[a[i]]) ++num,mp[a[i]]=num;
		a[i]=mp[a[i]];
		if (!mp[b[i]]) ++num,mp[b[i]]=num;
		b[i]=mp[b[i]];
	}
	if (!mp[s]) ++num,mp[s]=num;
	s=mp[s];
 
	for (int i=1;i<=n;++i) ++dog[a[i]];
	++dog[s];
	for (int i=1;i<=n;++i)
	{
		--dog[b[i]];
		if (dog[b[i]]<0) 
		{
			printf("-1\n");
			return 0;
		}
	}
//	printf("?\n");
	
	for (int i=1;i<=num;++i) fa[i]=i;
	for (int i=1;i<=n;++i) if (a[i]!=b[i])
	{
		++ans;
		br[a[i]]=br[b[i]]=1;
		merge(a[i],b[i]);
	}
	for (int i=1;i<=num;++i) if (br[i])
		if (find(i)==i) ++ans;
	printf("%d\n",max(ans-flag,0));
	return 0;
}
