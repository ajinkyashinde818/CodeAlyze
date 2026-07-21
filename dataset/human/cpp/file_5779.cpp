#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,size=1;
long long l;
int tr[100010][2];
bool vis[100100];
char s[100010];
int dep[100010];
long long sg[100010];
int cnt;
void add(int x)
{
	int nod=1;
	for (int i=1;i<=x;i++)
	{
		if (!tr[nod][s[i]-'0'])
			tr[nod][s[i]-'0']=++size,nod=size;
		else nod=tr[nod][s[i]-'0'];
	}
	vis[nod]=1;
}
void dfs(int x,int y)
{
	if (vis[x]) return;
	dep[x]=dep[y]+1;
	if (tr[x][0]) dfs(tr[x][0],x);
	if (tr[x][1]) dfs(tr[x][1],x);
	if (tr[x][0]==0||tr[x][1]==0) sg[++cnt]=l-dep[x]+1;
}
int main()
{
	scanf("%d",&n);
	scanf("%lld",&l);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		add(strlen(s+1));
	}
	dfs(1,0);
	long long ans=0;
	for (int i=1;i<=cnt;i++)
		ans^=(sg[i]&(-sg[i]));//,cout<<sg[i]<<endl;
	if (!ans) printf("Bob");
	else printf("Alice");
}
