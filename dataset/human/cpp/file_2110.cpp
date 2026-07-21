#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define eps LDBL_EPSILON
#define moder 1000000007
#define int long long
#define ll long long
#define double long double
#define INF LLONG_MAX/3
#define P pair<int,int>
#define prique priority_queue<int,vector<int>,greater<int>>
using namespace std;
int n, a[100010];
signed main() {
	int cnt = 0;
	bool f = false;
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		if (a[i] < 0)cnt++;
		if (!a[i])f = true;
	}
	if (f) {
		int ans = 0;
		rep(i, n)ans += abs(a[i]);
		cout << ans << endl;
	}
	else {
		if (cnt % 2 == 0) {
			int ans = 0;
			rep(i, n)ans += abs(a[i]);
			cout << ans << endl;
		}
		else {
			rep(i, n)a[i] = abs(a[i]);
			sort(a, a + n);
			int ans = 0;
			rep(i, n)ans += a[i];
			ans -= a[0] * 2;
			cout << ans << endl;
		}
	}
}
