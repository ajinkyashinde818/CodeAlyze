#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef pair<int,double> P;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<28;
const ll INF=1ll<<50;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const vi emp;
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
const int DX[8]={-1,-1,-1,0,0,1,1,1},DY[8]={1,0,-1,1,-1,1,0,-1};

struct point{
	double x,y;
	point operator+(point p){
		return point{x+p.x,y+p.y};
	}
	point operator-(point p){
		return point{x-p.x,y-p.y};
	}
	point operator*(double p){
		return point{x*p,y*p};
	}
	point operator/(double p){
		if(!p) return point{0,0}; 
		return point{x/p,y/p};
	}
	bool operator==(point p){
		return fabs(x-p.x)<eps&&fabs(y-p.y)<eps;
	}
	bool operator<(point p){
		if(fabs(x-p.x)>eps) return x<p.x;
		return y<p.y;
	}
};

class Graph{
	private:
	int V;
	vvp List;
	public:
	Graph(int v){
		V=v;
		List=vvp(v);
	}
	void add_edge(int s,int t,double c){
		List[s].push_back(P(t,c));
		List[t].push_back(P(s,c));
	}
	double DIJ(int s,int t){
/*		for(int i=0;i<V;i++){
			for(int j=0;j<List[i].size();j++){
				cout<<List[i][j].second<<' ';
			}
			cout<<endl;
		}*/
		priority_queue<P> que;
		vd d(V,INF);
		d[s]=0;
		que.push(P(s,0));
		while(!que.empty()){
			pair<ll,ll> p=que.top();
			que.pop();
			int v=p.first;
			if(d[v]<-p.second) continue;
			for(int i=0;i<List[v].size();i++){
				int F=List[v][i].first;
				double S=List[v][i].second;
				if(d[F]>d[v]+S){
					d[F]=d[v]+S;
					que.push(P(F,-d[F]));
				}
			}
		}
		return d[t];
	}
};


typedef pair<point,point> pp;
typedef vector<point> VP;
const point O{0,0};

double Length(point x,point y){
	point z=y-x;
	return sqrt(z.x*z.x+z.y*z.y);
}

void Point_in(point& p){
	cin>>p.x>>p.y;
}

point p,q;
int n;
VP c;
vi r;

int main(){
	cout<<syosu(11);
	Point_in(p);
	Point_in(q);
	cin>>n;
	c=VP(n);
	r=vi(n);
	for(int i=0;i<n;i++){
		Point_in(c[i]);
		cin>>r[i];
	}
	c.push_back(p);
	c.push_back(q);
	r.push_back(0);
	r.push_back(0);
	Graph g(n+2);
	for(int i=0;i<n+2;i++) for(int j=i+1;j<n+2;j++){
		double e=Length(c[i],c[j])-r[i]-r[j];
		if(e<0) e=0;
		g.add_edge(i,j,e);
	}
	cout<<g.DIJ(n,n+1)<<endl;
}
