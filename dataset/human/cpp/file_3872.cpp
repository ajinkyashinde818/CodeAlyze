#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <complex>
#include <numeric>
#include <cstdio>
#include <limits>
#include <iomanip>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR 
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long int;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;

double dis[1002][1002];
int preve[1002];
bool f[1002];

//struct edge {int from, to, cost;};

constexpr double EPS = 1e-10;
constexpr double PI  = acos(-1.0);
//constexpr int INF = INT_MAX;

template<class T> inline T sqr(T x) {return x*x;}

int main() {
	int xs, ys, xt, yt, n;
	cin >> xs >> ys >> xt >> yt >> n;
	LL x[1002], y[1002], r[1002];
	REP(i,1,n+1) cin >> x[i] >> y[i] >> r[i];
	x[0] = xs; y[0] = ys; r[0]= 0;
	x[n+1] = xt; y[n+1] = yt; r[n+1]= 0;
	REP(i,0,n+2) REP(j,i,n+2) {
		if (i == j) dis[i][j] = 0;
		else {
			dis[i][j] = dis[j][i] = max(0.0, sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])) - r[i] - r[j]);
			//cout << dis[i][j] << " " << sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])) << endl;
		}
	}
	//int ans[1002];
	vector<double> d(n+2);
	REP(i,0,n+2) {
		preve[i] = -1;
		f[i] = false;
		if (i) d[i] = std::numeric_limits<double>::max();
		else d[i] = 0;
	}
	while (true) {
		bool b = false;
		REP(i,0,n+2) {
			if (!(f[i])) {
				b = true;
				break;
			}
		}
		if (!b) break;
		double mindis = std::numeric_limits<double>::max();
		REP(i,0,n+2) {
			if (!(f[i])) mindis = min(mindis, d[i]);
		}
		int index = -1;
		REP(i,0,n+2) {
			if (!(f[i]) && mindis == d[i]) { index = i; break;}
		}
		f[index] = true;
		REP(i,0,n+2) {
			if (f[i]) continue;
			if (d[i] > d[index] + dis[index][i]) {
				d[i] = d[index] + dis[index][i];
				preve[i] = index;
			}	
		}
	}
	//cout << d[n+1] << endl;
	//REP(i,0,n+2) printf("%.9lf\n", d[i]);
	printf("%.10lf\n", d[n+1]);
	
	return 0;
}
