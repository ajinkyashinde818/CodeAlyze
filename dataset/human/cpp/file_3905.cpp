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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MP make_pair
#define MT make_tuple
#define EACH(i,c) for(auto i: c)
#define SORT(c) sort((c).begin(),(c).end())

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()

int main() {

	int xs, ys, xt, yt;
	scanf("%d %d %d %d",  &xs, &ys, &xt, &yt);
	int N;
	scanf("%d", &N);
	VI X(N + 2), Y(N + 2), R(N + 2);
	REP(i, N) scanf("%d %d %d", &X[i + 1], &Y[i + 1], &R[i + 1]);
	X[0] = xs; Y[0] = ys, R[0] = 0;
	X[N + 1] = xt, Y[N + 1] = yt, R[N + 1] = 0;

	vector<vector<double>> D(N + 2, vector<double>(N + 2, 0));
	REP(i, N + 2){
		REP(j, N + 2){
			D[i][j] = max(0.0, sqrt(1.0 * (X[i] - X[j]) * (X[i] - X[j]) +1.0 * (Y[i] - Y[j]) * (Y[i] - Y[j])) - R[i] - R[j]);
			D[j][i] = D[i][j];
//			cout << i << " "<< j << " " << D[i][j] << endl;;
		}
	}

	vector<double> dp(N + 2, 1e18);
	priority_queue<int, vector<int>, greater<int>> que;
	que.push(0);
	dp[0] = 0;
	while(!que.empty()){
		int cur = que.top();
//		cout << cur << endl;
		que.pop();
		REP(next, N + 2){
			if(dp[next] > dp[cur] + D[cur][next]){
				dp[next] = dp[cur] + D[cur][next];
				que.push(next);
			}
		}
	}

	printf("%.10f", dp[N + 1]);

	return 0;
}
