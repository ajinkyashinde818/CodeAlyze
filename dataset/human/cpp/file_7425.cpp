#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<iomanip>
#include<functional>
using namespace std;

int INF = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> P;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<ll> lsum(n + 1, 0), rsum(n + 1, 0);
	lsum[1] = a[1], rsum[1] = a[n];
	for (int i = 1; i < n; i++) {
		lsum[i + 1] = lsum[i] + a[i + 1];
		rsum[i + 1] = rsum[i] + a[n - i];
	}
	ll ans = 1e18;
	for (int i = 1; i < n; i++) {
		ans = min(ans, abs(lsum[i] - rsum[n - i]));
	}
	cout << ans << endl;
}
