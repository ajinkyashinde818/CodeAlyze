#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <functional>
#include <stack>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <array>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll MOD = 10e9 + 7;
const ll INF = LLONG_MAX;
const ll MAX_V = 10e3;
const double EPS = 10e-6;
const double PI = 3.14159265359;

//int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
//int d[] = {0,1,0,-1};
//int nx = x + d[i];
//int ny = y + d[(i+1)%4]

ll n, c, x[100005], v[100005], sum[100005]{},memo[2][100005][2],ans = 0;

int main() {

	cin >> n >> c;
	x[0] = 0; v[0] = 0;
	x[n + 1] = 0; v[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> v[i];
		sum[i] = sum[i-1] + v[i];
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)memo[i][0][j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		memo[0][i][0] = max(memo[0][i-1][0], sum[i] - sum[0] - x[i]);
		memo[0][i][1] = max(memo[0][i-1][1], sum[i] - sum[0] - x[i] * 2);
	}
	for (int i = 1; i <= n; i++) {
		memo[1][i][0] = max(memo[1][i-1][0],sum[n] - sum[n-i] - (c - x[n-i+1]));
		memo[1][i][1] = max(memo[1][i-1][1],sum[n] - sum[n-i] - (c - x[n-i+1]) * 2);
	}

	for (int i = 0; i <= n; i++) {
		ans = max(ans,max(memo[0][i][1] + memo[1][n - i][0], memo[0][i][0] + memo[1][n - i][1]));
	}
	cout << ans << endl;

	return 0;
}
