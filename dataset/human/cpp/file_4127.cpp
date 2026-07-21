#include <bits/stdc++.h>
using namespace std;
const double inf=1e10;
struct cir
{
	int x;double d;
	bool operator<(const cir &a)const{return d>a.d;}
};
cir mak(int xx,double dd){cir cc;cc.x=xx;cc.d=dd;return cc;}
double dis(double xx,double yy){return sqrt(xx*xx+yy*yy);}
int n,x[1005],y[1005],r[1005];
double c[1005][1005],dist[1005];
priority_queue<cir>pq;
int main()
{
	scanf("%d%d%d%d%d",&x[0],&y[0],&x[1],&y[1],&n);x[n+1]=x[1];y[n+1]=y[1];
	for(int i=1;i<=n;i++)scanf("%d%d%d",&x[i],&y[i],&r[i]);
	for(int i=0;i<n+1;i++)for(int j=i+1;j<=n+1;j++)c[i][j]=c[j][i]=max(0.0,dis(x[i]-x[j],y[i]-y[j])-r[i]-r[j]);
	fill(dist,dist+n+2,inf);dist[0]=0;
	pq.push(mak(0,0));
	while(!pq.empty())
	{
		cir cc=pq.top();pq.pop();
		for(int i=0;i<=n+1;i++)if(dist[i]>cc.d+c[cc.x][i])dist[i]=cc.d+c[cc.x][i],pq.push(mak(i,dist[i]));
	}
	printf("%.12f\n",dist[n+1]);
}
