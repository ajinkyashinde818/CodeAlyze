#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Circle
{
	long long x,y,r;
	double calc(const Circle &c)const
	{
		return max(sqrt((x-c.x)*(x-c.x)+(y-c.y)*(y-c.y))-r-c.r,0.0);
	}
}c[1010];
double dis[1010];
bool vis[1010];
int main()
{
	int n,mi;
	scanf("%lld%lld%lld%lld",&c[0].x,&c[0].y,&c[1].x,&c[1].y);
	c[0].r=0;
	c[1].r=0;
	scanf("%d",&n);
	n++;
	for(int i=2;i<=n;i++)
		scanf("%lld%lld%lld",&c[i].x,&c[i].y,&c[i].r);
	for(int i=1;i<=n;i++)
		dis[i]=1e100;
	dis[0]=0;
	memset(vis,0,sizeof(vis));
	while(!vis[1])
	{
		mi=-1;
		for(int i=0;i<=n;i++)
			if(!vis[i]&&(mi==-1||dis[i]<dis[mi]))
				mi=i;
		vis[mi]=true;
		for(int i=0;i<=n;i++)
			dis[i]=min(dis[i],dis[mi]+c[mi].calc(c[i]));
	}
	printf("%.10lf",dis[1]);
	return 0;
}
