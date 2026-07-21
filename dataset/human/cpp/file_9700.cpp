// A - Colorful Subsequence

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	string S;
	cin >> S;

	unordered_map<char, int> cnt;

	for (int i=0; i<N; i++) {
		cnt[S[i]]++;
	}

	ll ans = 1;
	for (auto itr : cnt) {
		ans *= itr.second + 1;
		ans %= MOD;
	}

	ans--;

	cout << ans << endl;

	return 0;
}
