#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
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
#define prique priority_queue
using namespace std;
signed main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int ans = 0;
	rep(i, n / r + 1) {
		rep(j, (n - i * r) / g + 1) {
			if ((n - i * r - j * g) % b == 0)ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
