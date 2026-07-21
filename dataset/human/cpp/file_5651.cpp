#include<bits/stdc++.h>
using namespace std;
int i,n,m,ch[100005][2],p,tot,j,ed[100005];
long long k,ans;
char c[100005];
long long lowbit(long long x)
{
	return -x&x;
}
void dfs(int i,int j)
{
	if(ed[i]==1)
		return;
	if(i==0)
	{
		ans^=lowbit(k-j+1);
		return;
	}
	dfs(ch[i][0],j+1);
	dfs(ch[i][1],j+1);
}
int main()
{
	scanf("%d %lld",&n,&k);
	tot=1;
	for(i=1;i<=n;++i)
	{
		scanf("%s",c);
		p=1;
		for(j=0;c[j];++j)
		{
			if(!ch[p][c[j]-'0'])
				ch[p][c[j]-'0']=++tot;
			p=ch[p][c[j]-'0'];
		}
		ed[p]=1;
	}
	dfs(1,0);
	puts(ans?"Alice":"Bob");
}
