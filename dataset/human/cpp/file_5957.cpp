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
#define MOD 1000000009

LL l[100002];
LL r[100002];

int main() {
	int n;
	LL c, ret=0;
	scanf("%d%lld", &n, &c);
	auto xv = vector<pair<LL, LL> >(n+2);
	xv[0] = MP(0, 0);
	REP(i, n) {
		LL x, v;
		scanf("%lld%lld", &x, &v);
		xv[i+1] = MP((LL)x, (LL)v);
	}
	xv[n + 1] = MP(c, 0);
	LL sum = 0;
	//l
	FOR(i, 1, n+1) {
		sum += xv[i].second;
		l[i] = max(l[i - 1], sum - xv[i].first);
		ret = max(ret, l[i]);
	}
	reverse(xv.begin(), xv.end());
	//r
	sum = 0;
	FOR(i, 1, n + 1) {
		sum += xv[i].second;
		r[i] = max(r[i - 1], sum - (c - xv[i].first));
		ret = max(ret, r[i]);
	}
	//r
	FOR(i,1,n+1) {
		ret = max(ret, r[i] - (c - xv[i].first) + l[n - i]);
	}
	//l
	reverse(xv.begin(), xv.end());
	//r
	FOR(i, 1, n + 1) {
		ret = max(ret, l[i] - xv[i].first + r[n - i]);
	}
	cout << ret << endl;
	return 0;
}
