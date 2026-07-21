#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;


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

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

typedef complex<double> P;
typedef pair<P,double> C;

double d[1010][1010];


double func(C &a, C &b){
	if(abs(a.F-b.F) <= a.S+b.S){
		return 0;
	}
	return abs(a.F-b.F)-a.S-b.S;
}


void mainmain(){
	P s,g;
	double aa,bb;
	scanf("%lf%lf", &aa, &bb);
	s=P(aa,bb);
	scanf("%lf%lf", &aa, &bb);
	g=P(aa,bb);
	int n;
	scanf("%d", &n);
	vector<C> v(n);
	rep(i,n){
		double a,b,c;
		scanf("%lf%lf%lf", &a, &b, &c);
		v[i] = mkp(P(a,b), c);
	}
	n += 2;
	v.PB(mkp(s,0));
	v.PB(mkp(g,0));
	rep(i,n){
		rep(j,i){
			double dis = func(v[i],v[j]);
			d[i][j] = dis;
			d[j][i] = dis;
		}
	}
	rep(i,n) d[i][i] = 0;
	rep(k,n){
		rep(i,n){
			rep(j,n){
				mins(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	printf("%.10lf\n", d[n-2][n-1]);
}


signed main() {
    mainmain();
}
