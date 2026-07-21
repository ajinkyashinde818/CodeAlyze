#include <bits/stdc++.h>
using namespace std;

int acnt[200010];
int bcnt[200010];
int main() {
	int n; cin >> n;
	int a[n]; for(int i = 0; i < n; ++i) cin >> a[i];
	int b[n]; for(int i = 0; i < n; ++i) cin >> b[i];
	for(int i = 0; i < n; ++i) {
		++acnt[a[i]];
		++bcnt[b[i]];
	}
	for(int i = 1; i <= n; ++i) {
		if(acnt[i] + bcnt[i] > n) {
			cout << "No" << '\n';
			return 0;
		}
		acnt[i] += acnt[i - 1];
		bcnt[i] += bcnt[i - 1];
	}
	int maxi = 0;
	for(int i = 1; i <= n; ++i) {
		maxi = max(maxi, acnt[i] - bcnt[i - 1]);
	}
	int ans[n];
	for(int i = 0; i < n; ++i) {
		ans[(i + maxi) % n] = b[i];
	}
	cout << "Yes" << '\n';
	for(int i = 0; i < n; ++i) {
		cout << ans[i] << (i == n - 1 ? "\n" : " ");
	}
	return 0;
}
