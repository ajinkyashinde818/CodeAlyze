#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
	ll n, C; cin >> n >> C;
	vector<ll> x(n, 0), c(n, 0), x1(n), c1(n), q(n);
	for(int i = 0; i < n; i++){
		cin >> x[i] >> c[i]; q[i] = c[i];
		x1[i] = C - x[i]; c1[i] = c[i];
	}
	reverse(x1.begin(), x1.end());
	reverse(c1.begin(), c1.end());
	for(int i = 1; i < n; i++){
		c[i] += c[i - 1];
		c1[i] += c1[i - 1];
	}
	vector<ll> data1(n + 1, 0), data2(n + 1, 0);
	for(int i = 1; i <= n; i++){
		data1[i] = c[i - 1] - x[i - 1];
		data2[i] = c1[i - 1] - x1[i - 1];
	}
	vector<ll> data_left(n + 1, 0), data_right(n + 1, 0);
	for(int i = 1; i  <= n; i++){
		data_left[i] = max(data_left[i - 1], data1[i]);
		data_right[i] = max(data_right[i - 1], data2[i]);
	}
	ll ans = 0;
	for(int left = 0; left <= n; left++){
		if(left == 0) ans = max(ans, data_right[n]);
		ans = max(ans, data1[left] - x[left - 1] + data_right[n - left]);
	}
	for(int right = 0; right <= n; right++){
		if(right == 0) ans = max(ans, data_left[n]);
		else ans = max(ans, data2[right] - x1[right - 1] + data_left[n - right]);
	}
	cout << ans << endl;
}
