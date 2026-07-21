#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;

int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	for (int i = 0; i < 2 * N; i += 2) {
		if (S[i] == 'B') S[i] = 'W';
		else S[i] = 'B';
	}
	ll ans = 1;
	int L = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (S[i] == 'W') {
			L++;
		}
		else {
			if (L == 0) {
				cout << 0 << endl;
				return 0;
			}
			(ans *= L) %= MOD;
			L--;
		}
	}
	if (L > 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= N; i++) (ans *= i) %= MOD;
	cout << ans << endl;
}
