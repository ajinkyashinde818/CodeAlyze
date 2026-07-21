#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include<utility>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
typedef long long int ll;
const double EPS=1e-10;

bool equals(double a,double b)
{
	return a>b?a-b<EPS:b-a<EPS;
}

class Point
{
public:
	double x;
	double y;
	Point(double inx=0.0,double iny=0.0):x(inx),y(iny){}
	Point operator+(const Point &p){return Point(x+p.x,y+p.y);}
	Point operator-(const Point &p){return Point(x-p.x,y-p.y);}
	Point operator*(const double k){return Point(x*k,y*k);}
	Point operator/(const double k){return Point(x/k,y/k);}
	Point operator=(const Point &p){x=p.x;y=p.y;return *this;}
	bool operator<(const Point &p)const{return x!=p.x?x<p.x:y<p.y;}
	bool operator==(const Point &p)const{return equals(x,p.x)&&equals(y,p.y);}
	double norm()
	{
		return x*x+y*y;
	}
	double abs()
	{
		return sqrt(norm());
	}
};

typedef Point Vector;

class Segment
{
public:
	Point p1;
	Point p2;
	Segment(Point inp1=Point(),Point inp2=Point()):p1(inp1),p2(inp2){}
	bool operator==(const Segment s)const
	{
		return p1.x==p2.x?s.p1.x==s.p2.x&&s.p1.x==p1.x:s.p1.x==s.p2.x?false:
		(p2.y-p1.y)/(p2.x-p1.x)==(s.p2.y-s.p1.y)/(s.p2.x-s.p1.x);
	}
	Vector getvector()
	{
		return p2-p1;
	}
};

typedef Segment Line;

class Circle
{
public:
	Point c;
	double r;
	Circle(Point inc=Point(),double inr=0.0):c(inc),r(inr){}
};

typedef vector<Point> Polygon;

double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}

double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}

double norm(Vector a)
{
	return a.x*a.x+a.y*a.y;
}

double abs(Vector a)
{
	return sqrt(norm(a));
}

double getdistance(Point a,Point b)
{
	return abs(a-b);
}

double get(Circle c1,Circle c2)
{
	return max(0.0,getdistance(c1.c,c2.c)-c1.r-c2.r);
}
const int MAX=1100;
const double INFTY=1e10;

int n,col[MAX];
double d[MAX];
vector<pair<int,double>> Q[MAX];//target,weight

void dijkstra(int s)
{
	priority_queue<pair<double,int>> PQ;//weight,id
	for(int i=0;i<n;i++)
	{
		d[i]=INFTY;
		col[i]=0;
	}
	d[s]=0.0;
	PQ.push(make_pair(0.0,s));
	col[s]=1;
	
	while(!PQ.empty())
	{
		pair<double,int> f=PQ.top();PQ.pop();
		int u=f.second;
		col[u]=2;
		if(d[u]<f.first*(-1))continue;
		for(int j=0;j<Q[u].size();j++)
		{
			int v=Q[u][j].first;
			if(col[v]==2)continue;
			if(d[u]+Q[u][j].second<d[v])
			{
				d[v]=d[u]+Q[u][j].second;
				PQ.push(make_pair(d[v]*(-1),v));
				col[v]=1;
			}
		}
	}
	
	return;
}

int main()
{
	Circle st,go;
	cin>>st.c.x>>st.c.y>>go.c.x>>go.c.y;
	st.r=go.r=0.0;
	int V;cin>>V;
	n=V+2;
	Circle c[1100];
	c[0]=st;c[V+1]=go;
	for(int i=1;i<=V;i++)
	{
		cin>>c[i].c.x>>c[i].c.y>>c[i].r;
	}
	for(int i=0;i<=V+1;i++)
	{
		for(int j=i+1;j<=V+1;j++)
		{
			double sto=get(c[i],c[j]);
			Q[i].push_back(make_pair(j,sto));
			Q[j].push_back(make_pair(i,sto));
		}
	}
	dijkstra(0);
	cout<<fixed<<setprecision(9)<<d[V+1]<<endl;
	return 0;
}
