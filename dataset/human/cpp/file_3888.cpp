#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const long double EPS=1e-13;
int n;
long double S[2],E[2];
long double d[MAXN];
bool vis[MAXN];
struct circle
{
	long double x,y,r;
}C[MAXN];
long double jl(int i,int j)
{
	long double o=sqrt((C[i].x-C[j].x)*(C[i].x-C[j].x)+(C[i].y-C[j].y)*(C[i].y-C[j].y));
	o=o-C[i].r-C[j].r;
	if(o<EPS)
		o=0.0;
	return o;
}
void dj(int s,int t)
{
	fill(d,d+MAXN,-1);
	int mi=s;
	vis[s]=1;
	d[s]=0.0;
	while(1)
	{
		int k=mi;
		mi=-1;
		if(k==t)
			break;
		vis[k]=1;
		for(int i=1;i<=n+2;i++)
		{
			if(vis[i])
				continue;
			long double o=jl(k,i);
			if((d[i]==-1)||d[k]+o<d[i])
			{
				d[i]=d[k]+o;
			}
			if(d[i]!=-1&&(mi==-1||d[mi]>d[i]))
				mi=i;
		}
	}
}
int main()
{
	scanf("%Lf %Lf %Lf %Lf",&S[0],&S[1],&E[0],&E[1]);
	scanf("%d",&n);
	C[1].x=S[0];
	C[1].y=S[1];
	C[1].r=0;
	C[n+2].x=E[0];
	C[n+2].y=E[1];
	C[n+2].r=0;
	for(int i=2;i<=n+1;i++)
	{
		scanf("%Lf %Lf %Lf",&C[i].x,&C[i].y,&C[i].r);
	}
	dj(1,n+2);
	cout<<setiosflags(ios::fixed)<<setprecision(10)<<d[n+2];
}
