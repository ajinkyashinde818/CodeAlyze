#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100000;

int main() {
	int n;
	cin >> n;
	ll a[N];
	rep(i, n) cin >> a[i];

	int count_minus = 0;
	ll max_minus = -INFL;
	ll min_plus = INFL;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] >= 0) {
			min_plus = min(a[i], min_plus);
		}
		else {
			count_minus++;
			max_minus = max(a[i], max_minus);
		}
		ans += abs(a[i]);
	}

	if(count_minus % 2 == 1) {
		ans -= 2 * min(min_plus, -max_minus);
	}
	cout << ans << endl;
}
