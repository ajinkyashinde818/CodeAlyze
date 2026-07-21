#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;
ll dp[525252];


int main() {
	int n;
	cin >> n;
	dp[0] = 0;
	for (int i=1; i<=n; i++) {
		ll a;
		cin >> a;
		dp[i] = dp[i-1] + a;
	}
	ll res = 1000000000000000000LL;
	for (int i=1; i<n; i++) {
		ll diff = abs(dp[i] - (dp[n]-dp[i]));
		res = min(res, diff);
	}
	cout << res << endl;
}
