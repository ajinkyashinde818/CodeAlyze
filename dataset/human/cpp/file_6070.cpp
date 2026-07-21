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

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(auto i: c)
#define SORT(c) sort((c).begin(),(c).end())

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N, C;
	cin >> N >> C;
	vector<LL> X(N), V(N), sum1(N, 0), sum2(N, 0), max1(N, 0), max2(N, 0);
	REP(i, N) cin >> X[i] >> V[i];

	sum1[0] = V[0];
	sum2[0] = V[N - 1];
	cerr << sum1[0] << " " << sum2[0] << endl;
	FOR(i, 1, N){
		 sum1[i] = sum1[i - 1] + V[i];
		 sum2[i] = sum2[i - 1] + V[N - 1 - i];
		 cerr << sum1[i] << " " << sum2[i] << endl;
 	}
	cerr << endl;

	max1[0] = sum1[0] - X[0];
	max2[0] = sum2[0] - (C - X[N - 1]);
	cerr << max1[0] << " " << max2[0] << endl;
	FOR(i, 1, N){
		 max1[i] = max(max1[i - 1], sum1[i] - X[i]);
		 max2[i] = max(max2[i - 1], sum2[i] - (C - X[N - 1 - i]));
		 cerr << max1[i] << " " << max2[i] << endl;
	}
	
	LL ret = 0;
	REP(i, N){
		ret = max(ret, max1[i]);
		ret = max(ret, max2[i]);
		if(1 < N && i < N - 1) ret = max(ret, max1[i] - X[i] + max2[N - 2 - i]);
		if(1 < N && i < N - 1) ret = max(ret, max2[i] - (C - X[N - 1 - i]) + max1[N - 2 - i]);
	}

	cout << max(0LL, ret) << endl;

	return 0;
}
