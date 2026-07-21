#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <array>
#include <climits>
#include <bitset>
#include <cassert>


// BEGIN CUT HERE
#ifdef _MSC_VER
#include <agents.h>
#endif
// END CUT HERE 

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define UNIQUE(v) (v).erase(unique(ALL(v)), (v).end())
#define MP make_pair
#define MT make_tuple

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int main(){
	int t, d;
	cin >> t >> d;
	int ta, tb, da, db;
	cin >> ta >> tb >> da >> db;

	double ans = 1e9;
	rep(i, 1001) rep(j, 1001){
		if (da*i + db*j < 1) continue;
		if (da*i + db*j > d) continue;
		double va = da*i, vb = db*j;
		double tt = (ta*va + tb*vb) / (va + vb);
		ans = min(ans, abs(tt-t));
	}
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << ans << endl;



	return 0;
}
