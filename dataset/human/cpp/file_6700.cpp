#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
const double EPS=1e-10;

double add(double a,double b)
{
	//if(abs(a+b)<EPS*(abs(a)+abs(b)))return 0;
	return a+b;
}

typedef struct Vec{
	double x,y;
	Vec(){}
	Vec(double x,double y):x(x),y(y){}
	Vec operator +(Vec v){return Vec(add(x,v.x),add(y,v.y));}
	Vec operator -(Vec v){return Vec(add(x,-v.x),add(y,-v.y));}
	Vec operator *(double d){return Vec(x*d,y*d);}
}Vec;

double dot(Vec a,Vec b){return add(a.x*b.x,a.y*b.y);}
double det(Vec a,Vec b){return add(a.x*b.y,-a.y*b.x);}

typedef struct Cer{
	double r;
	Vec cp;
}Cer;

double vabs(Vec a)
{
	return hypot(a.x,a.y);
}

double ch(Vec a,Vec b,Cer c)
{
	if(dot(b-a,c.cp-a)<EPS)return vabs(c.cp-a);
	if(dot(a-b,c.cp-b)<EPS)return vabs(c.cp-b);
	return fabs(det(b-a,c.cp-a))/vabs(b-a);
}

int chC(Vec a,Cer c)
{
	return hypot(a.x-c.cp.x,a.y-c.cp.y)<=c.r?1:0;
}

int N,M,i,j,f;
double m,d;
Cer W[100];

int main()
{
	for(;scanf("%d",&N),N;)
	{
		for(i=0;i<N;i++)
			scanf("%lf%lf%lf",&W[i].cp.x,&W[i].cp.y,&W[i].r);
		scanf("%d",&M);
		for(i=0;i<M;i++)
		{
			f=0;
			Vec t,s;
			scanf("%lf%lf%lf%lf",&t.x,&t.y,&s.x,&s.y);
			for(j=0;j<N;j++)
			{
				if(chC(s,W[j])&&chC(t,W[j]))continue;
				if(ch(t,s,W[j])<=W[j].r)
					f=1;
			}
			puts(f?"Safe":"Danger");
		}
	}
	return 0;
}
