#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	long long sum = 0;
	for(int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	long long ans = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
	for(int i = 0; i < n - 1; i++) sum -= 2 * a[i], ans = min(ans, llabs(sum));
	cout << ans;
}
