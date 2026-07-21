// D - Flipping Signs

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int min_abs = INF;
	int cnt_neg = 0;
	ll tot = 0;
	for (int i=0; i<N; i++) {
		int A;
		cin >> A;
		min_abs = min(min_abs, abs(A));
		if (A < 0) cnt_neg++;
		tot += abs(A);
	}

	ll ans;
	if (cnt_neg % 2 == 0) {
		ans = tot;
	} else {
		ans = tot - 2 * min_abs;
	}

	cout << ans << endl;

	return 0;
}
