#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#else

#endif

using namespace std;


namespace{
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#define double long double
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8
static const int INF=1<<24;

int check(double x1,double y1,double x2,double y2,double r2){
	double xy=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1),r=r2*r2;
	if(r-xy<-EPS) return 1;
	else return -1;
}


void mainmain(){
	int n;
	while(cin>>n,n){
		vector<pair<pair<double,double>,double > >  a(n);
		rep(i,n){
			cin>>a[i].F.F>>a[i].F.S>>a[i].S;
		}
		int m;
		cin>>m;
		// vector<pair<double,double> > b(m);
		rep(l,m){
			double b[4];
			cin>>b[0]>>b[1]>>b[2]>>b[3];
			bool f=false;
			double x=b[0],y=b[1];
			double dx=(b[2]-b[0])/10000.0,dy=(b[3]-b[1])/10000.0;
			rep(i,n){
				int t=check(b[0],b[1],a[i].F.F,a[i].F.S,a[i].S);
				reep(j,1,10001){
					int t1=check(x+dx*j,y+dy*j,a[i].F.F,a[i].F.S,a[i].S);
						// cout<<x+dx*j<<" "<<y+dy*j<<" "<<a[i].F.F<<" "<<a[i].F.S<<" "<<a[i].S<<endl;
					if(t!=t1){
						f=true;
						break;
					}	
				}
				if(f) break;
			}
			if(f) cout<<"Safe\n";
			else cout<<"Danger\n";
		}
	}
	// cout<<check(0,3,3,3,3)<<endl;
	// cout<<check(-1,3,3,3,3)<<endl;
	// cout<<check(0.5,0,1,0,1)<<endl;
}



}
main() try{
    mainmain();
}
catch(...){
}
