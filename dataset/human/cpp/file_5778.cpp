#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+9;

int n;
ll l,ans;
char s[N];
int ch[N<<1][2],tot;

inline ll calc(ll depth)
{
	ll dlt=l-depth;
	ll ret=1;
	while(dlt && !(dlt&1))
		ret<<=1,dlt>>=1;
	return ret;
}

inline void insert(char *str)
{
	int len=strlen(str+1);
	int now=0;
	for(int i=1;i<=len;i++)
	{
		if(!ch[now][str[i]-'0'])
			ch[now][str[i]-'0']=++tot;
		now=ch[now][str[i]-'0'];
	}
}

inline void dfs(int u,int depth)
{
	if(depth==l)return;
	if(ch[u][0])
		dfs(ch[u][0],depth+1);
	else
		ans^=calc(depth);
	if(ch[u][1])
		dfs(ch[u][1],depth+1);
	else
		ans^=calc(depth);
}

int main()
{
	if(fopen("vj.in","r"))
	{
		freopen("vj.in","r",stdin);
		freopen("vj.out","w",stdout);
	}

	scanf("%d%lld",&n,&l);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		insert(s);
	}
	dfs(0,0);

	puts(ans?"Alice":"Bob");
	return 0;
}
