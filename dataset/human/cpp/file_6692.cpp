#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <complex>
using namespace std;

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define EPS 1e-8
#define DEB 0

typedef complex<double> P;

class circle{
  public:
	int x,y,r;
	circle(int _x, int _y, int _r){
		x=_x; y=_y; r=_r;
	}
};

double dot(P a, P b){
	return a.real()*b.real() + a.imag()*b.imag();
}
double cross(P a, P b){
	return a.real()*b.imag() - a.imag()*b.real();
}

double distance_ls_p(P p0, P p1, P p2){
	if( dot(p1-p0, p2-p0)<-EPS ) return abs(p2-p0);
	if( dot(p0-p1, p2-p1)<-EPS ) return abs(p2-p1);
	return abs(cross(p1-p0,p2-p0))/abs(p1-p0);
}

bool inside(circle& c, int x, int y){
	return (c.x-x)*(c.x-x) + (c.y-y)*(c.y-y) <= c.r*c.r ;
}

int main(){
	int n,m;
	vector<circle> vc;
	
	while(scanf("%d",&n),n){
		vc.clear();
		rep(i,n){
			int a,b,c; scanf("%d%d%d",&a,&b,&c);
			vc.pb( circle(a,b,c) );
		}
		scanf("%d",&m);
		rep(i,m){
			bool f = false;
			int tx,ty,sx,sy; scanf("%d%d%d%d",&tx,&ty,&sx,&sy);
			rep(j,n){
				if(	(inside(vc[j],tx,ty) && !inside(vc[j],sx,sy)) ||
					(!inside(vc[j],tx,ty) && inside(vc[j],sx,sy)) ){
					f = true;
#if DEB
					puts("hoge");
#endif					
					break;
				}else if( !(inside(vc[j],tx,ty) && inside(vc[j],sx,sy)) &&
						  (distance_ls_p(P(tx,ty),P(sx,sy),P(vc[j].x,vc[j].y))<=vc[j].r) ){
					f = true;
#if DEB
					puts("uguu");
#endif					
					break;
				}
			}
			puts(f ? "Safe" : "Danger");
		}
	}
	return 0;
}
