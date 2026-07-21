#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int read()
{
    char c=getchar();int f=1,sum=0;
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
int n,maxa;
int vis[100005];
void init()
{
	int sum=1;vis[1]=2;
	for(int i=2;i;i++)
	{
		if(sum+i>100000) break;
		sum+=i;vis[sum]=i+1;
		maxa=max(maxa,vis[sum]);
	}
}
vector<int> v[505];
int main()
{
	init();
	n=read();if(!vis[n]) return !puts("No");
	int m=1,now=0;
	while(now<n)
	{
		for(int i=1;i<=m;i++) v[i].push_back(i+now);
		for(int i=1;i<=m;i++) v[m+1].push_back(i+now);
		now+=m;m++;
	}
	puts("Yes");printf("%d\n",vis[n]);
	for(int i=1;i<=vis[n];i++)
	{
		printf("%d",v[i].size());
		for(int j=0;j<v[i].size();j++) printf(" %d",v[i][j]);puts("");
	}
	return 0;
}
