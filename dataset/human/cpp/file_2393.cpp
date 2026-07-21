#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <cstring>
#include <functional>
//#include<unordered_map>
//#include<unordered_set>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P; 
const int N = 1000006;
//////////////////////////////

int n;
Int a[N];
Int dp[N][2];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0][0] = 0;
	dp[0][1] = -LINF;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1] - a[i]);
		dp[i][1] = max(dp[i - 1][0] - a[i], dp[i - 1][1] + a[i]);
	}
	cout << dp[n][0] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}
