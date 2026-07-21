#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <functional>
#include <string>
#include <cstdlib>
#include <numeric>
#include <cstdbool>
#include <map> 
#include<set>
#include<queue>

typedef long long ll;


#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1000000000000000;
const ll inf = -1e18;
typedef pair<int, int> P;
ll ma = 1000000000 + 7;
ll h, w, n,k; string s;
char maze[60][60];
int dis[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll dp[100010][2];
int gcd(int x, int y) {
	if (x % y == 0) return y;
	return gcd(y, x % y);

}
int main() {
	cin >> n;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	dp[0][0] = inf;
	dp[0][1] = inf;
	for(ll i=1;i<n;i++) {
		if (i == 1) {
			dp[i][0] = a[i - 1] + a[i];
			dp[i][1] = -a[i - 1] - a[i];
		}
		else {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
			dp[i][1] = max(dp[i - 1][0] - 2 * a[i - 1] - a[i], dp[i - 1][1] + 2 * a[i - 1] - a[i]);
		}
	}
	cout << max(dp[n-1][0], dp[n-1][1]) << endl;
}
