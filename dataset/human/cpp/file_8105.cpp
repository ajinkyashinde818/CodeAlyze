#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main() {
	int n;
	cin >> n;
	vector<ll> sum(n), a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sum[0] = a[0];
	for(int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i];
	ll out = (ll)1e18 + 10;
	for(int i = 0; i < n - 1; i++){
		out = min(out, (ll)abs(sum[i] - (sum[n - 1] - sum[i])));
	}
	cout << out << endl;
}
