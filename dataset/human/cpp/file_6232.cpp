#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

long long c;
long long v[100000];
int n;
long long x[100000];
long long d[100000];

long long solve() {
	long long ans = 0;
	long long curr = 0;
	for (int i = 0; i < n; i++) {
		curr += v[i];
		ans = max(ans, curr - x[i]);
	}
	return ans;
}

long long solve1() {
	set<pair<long long, int> > st;
	long long curr = 0;
	for (int i = 0; i < n; i++) {
		curr += v[i];
		d[i] = curr - x[i];
		st.insert({-d[i], i});
	}
	long long ans = 0;
	long long sum = 0;
	for (int i = n - 1; i > 0; i--) {
		sum += v[i];
		st.erase({-d[i], i});
		ans = max(ans, sum + (-(st.begin()->first)) - 2 * (c - x[i]));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> v[i];
	}
	
	long long ans = 0;
	ans = max(ans, solve());
	ans = max(ans, solve1());
	
	reverse(v, v + n);
	reverse(x, x + n);
	for (int i = 0; i < n; i++) {
		x[i] = c - x[i];
	}
	ans = max(ans, solve());
	ans = max(ans, solve1());
	cout << ans;
	
	return 0;
}
