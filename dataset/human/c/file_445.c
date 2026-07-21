#include<stdio.h>
#include<math.h>
struct P{double x,y;};
struct W{P p;double r;}w[100];
double D(P p){return hypot(p.x,p.y);}
double I(P a,P b){return a.x*b.x+a.y*b.y;}
double O(P a,P b){return a.x*b.y-a.y*b.x;}
P F(P l,P r){P p={l.x-r.x,l.y-r.y};return p;}
double S(P a,P b,P c)
{
	if(I(F(b,a),F(c,a))<1e-9)return D(F(c,a));
	if(I(F(a,b),F(c,b))<1e-9)return D(F(c,b));
	return fabs(O(F(b,a),F(c,a)))/D(F(b,a));
}
int main()
{
	P a,b;
	int i,n,m;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;++i)scanf("%lf%lf%lf",&w[i].p.x,&w[i].p.y,&w[i].r);
		for(scanf("%d",&m);m--;)
		{
			scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
			for(i=0;i<n;++i)
			{
				if(D(F(a,w[i].p))<=w[i].r&&D(F(b,w[i].p))<=w[i].r)continue;
				if(S(a,b,w[i].p)<=w[i].r){puts("Safe");goto E;}
			}
			puts("Danger");
E:;
		}
	}
	return 0;
}
