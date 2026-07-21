#include<algorithm>
#include<iostream>
using namespace std;

long long v[100004], x[100004];
long long ri[100004], lef[100004];

int main() {
	long long n, c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> v[i];
	}
	x[0] = v[0] = 0;
	x[n + 1] = c;
	v[n + 1] = 0;
	long long ans = 0;
	ri[0] = lef[0] = 0;
	long long now = 0;
	for (int i = 1; i <= n; i++) {
		now = now + v[i] - (x[i] - x[i - 1]);
		if (now>ri[i - 1]) {
			ri[i] = now;
		}
		else {
			ri[i] = ri[i - 1];
		}
	}
	now = 0;
	lef[0] = 0;
	for (int i = 1; i <= n; i++) {
		now = now + v[n - i + 1] - (x[n + 2 - i] - x[n + 1 - i]);
		if (now>lef[i - 1]) {
			lef[i] = now;
		}
		else {
			lef[i] = lef[i - 1];
		}
	}
	for (int i = 0; i< n; i++) {
		long long p;
		p = ri[i] + lef[n - i] - x[i];
		ans = max(ans, p);
	}
	for (int i = 0; i<n; i++) {
		ans = max(ans, lef[i] + ri[n - i] - c + x[n + 1 - i]);
	}
	cout << ans << endl;
}
