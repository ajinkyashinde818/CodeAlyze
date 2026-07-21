//Kaori Miyazono, did I reach you ?
//"I can't die because... I'm the one who will protect you." -Asuna Yuuki

#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

int n;
long long int c;
long long int x[N], v[N];
long long int best[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> c;
	for(int i = 0; i < n; i++) cin >> x[i] >> v[i];
	long long int cur = 0;
	for(int i = n - 1; i >= 0; i--) {
		cur += v[i];
		best[i] = cur - (c - x[i]);
		if (i + 1 < n) best[i] = max(best[i], best[i + 1]);
	}
	long long int ans = 0;
	cur = 0;
	for(int i = 0; i < n; i++) {
		cur += v[i];
		ans = max(ans, cur - x[i] + max(0ll, best[i + 1] - x[i]));
	}
	memset(best, 0, sizeof best);
	cur = 0;
	for(int i = 0; i < n; i++) {
		cur += v[i];
		best[i] = cur - x[i];
		if (i > 0) best[i] = max(best[i], best[i - 1]);
	}
	cur = 0;
	for(int i = n - 1; i >= 0; i--) {
		cur += v[i];
		ans = max(ans, cur - (c - x[i]) + max(0ll, best[i - 1] - (c - x[i])));
	}
	cout << ans << '\n';
	return 0;
}
