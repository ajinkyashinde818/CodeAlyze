#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>
#include <cstdint>
#include <tuple>
#include <regex>
#include <numeric>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MOD 1000000007
#define SQ(x) ((x)*(x))

const int N = 1005;
double d[N][N];
int x[N], y[N], r[N];
double dp[N];
bool vis[N];

int main() {
	int xs, ys, xt, yt, n;
	scanf("%d%d%d%d%d", &xs, &ys, &xt, &yt, &n);
	x[0] = xs;
	y[0] = ys;
	x[n + 1] = xt;
	y[n + 1] = yt;
	REP(i, n)scanf("%d%d%d", &x[i + 1], &y[i + 1], &r[i + 1]);
	REP(i, n + 2)FOR(j, i + 1, n + 2)d[i][j] = d[j][i] = max(sqrt(SQ(x[i] * 1.0 - x[j]) + SQ(y[i] * 1.0 - y[j])) - (r[i] + r[j]), 0.0);
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
	q.push(MP(0.0, 0));
	REP(i, n + 2)dp[i] = 1.0e18;
	dp[0] = 0.0;
	while (!q.empty()) {
		auto tmp = q.top();
		q.pop();
		int idx = tmp.second;
		double dist = tmp.first;
		if (vis[idx])continue;
		vis[idx] = true;
		dp[idx] = dist;
		REP(i, n+2) {
			if (vis[i]) continue;
			q.push(MP(dist + d[idx][i], i));
		}
	}
	printf("%.12f\n", dp[n + 1]);
	return 0;
}
