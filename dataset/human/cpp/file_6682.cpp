#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;

#define dump(n) cout<<"# "<<#n<<"="<<(n)<<endl
#define debug(n) cout<<__FILE__<<","<<__LINE__<<": #"<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();i++)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

const double EPS=1e-10;

int Signum(double x)
{
	return abs(x)<EPS?0:x>0?1:-1;
}

typedef complex<double> Point;
struct Circle{
	Point c;
	double r;
	Circle(){}
	Circle(Point c,double r):c(c),r(r){}
};

double Dot(Point p1,Point p2)
{
	return real(conj(p1)*p2);
}

double Cross(Point p1,Point p2)
{
	return imag(conj(p1)*p2);
}

int CCW(Point a,Point b,Point c)
{
	Point d1=b-a,d2=c-a;
	double sign=Signum(Cross(d1,d2));
	if(sign)
		return sign;
	if(Dot(d1,d2)<-EPS)
		return -2;
	if(norm(d1)<norm(d2)-EPS)
		return 2;
	return 0;
}

Point Proj(Point a,Point b)
{
	return b*Dot(a,b)/norm(b);
}

string solve(Point t,Point o,const vector<Circle>& cirs)
{
	int n=cirs.size();
	rep(i,n){
		double r=cirs[i].r;
		Point c=cirs[i].c;
		bool out_t=r<abs(c-t);
		bool out_o=r<abs(c-o);
		if(out_t^out_o)
			return "Safe";
		if(out_t && out_o){
			Point p=t+Proj(c-t,o-t);
			if(abs(p-c)<r+EPS && CCW(t,p,o)==2)
				return "Safe";
		}
	}
	return "Danger";
}

int main()
{
	for(int n,m;cin>>n,n;){
		vector<Circle> cirs(n);
		rep(i,n)
			cin>>real(cirs[i].c)>>imag(cirs[i].c)>>cirs[i].r;
		cin>>m;
		vector<Point> t(m),o(m);
		rep(i,m)
			cin>>real(t[i])>>imag(t[i])>>real(o[i])>>imag(o[i]);
		
		rep(i,m)
			cout<<solve(t[i],o[i],cirs)<<endl;
	}
	
	return 0;
}
