#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
int son[100005][2];
int cnt=1;
int n;
long long l;
char str[100005];
long long ans;
long long lowbit(long long x)
{
	return x&-x;
}
void dfs(int now,int dep)
{
	if(son[now][0]==0 && son[now][1]==0)	return;
	if(son[now][0]==0)	ans^=lowbit(l-dep);
	if(son[now][1]==0)	ans^=lowbit(l-dep);
	if(son[now][0])	dfs(son[now][0],dep+1);
	if(son[now][1])	dfs(son[now][1],dep+1);
}
int main()
{
	read(n);
	read(l);
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		int len=strlen(str);
		int now=1;
		for(int i=0;i<len;i++)
		{
			if(!son[now][str[i]-'0'])	son[now][str[i]-'0']=++cnt;
			now=son[now][str[i]-'0'];
		}
	}
	dfs(1,0);
	if(ans)
		printf("Alice\n");
	else
		printf("Bob\n");
	return 0;
}
