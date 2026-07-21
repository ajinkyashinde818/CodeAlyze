#include <cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll a[200005];
int main() {
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ll ans = 2*inf;
	ll sum2 = 0;
	for (int i = n - 1; i > 0; i--) {
		sum2 += a[i];
		sum -= a[i];
		
		ans = min(ans, abs(sum-sum2));
	}
	cout << ans << endl;
	return 0;
}
