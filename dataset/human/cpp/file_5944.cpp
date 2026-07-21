#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <queue>
#include <map>
#include <tuple>
using namespace std;

long long N, D, X[1 << 18], C[1 << 18], L[1 << 18];

long long solve() {
	long long sc = 0;
	for (int i = 0; i < N; i++) { sc += C[i]; L[i] = sc - X[i]; }
	for (int i = 1; i < N; i++) L[i] = max(L[i], L[i - 1]);

	long long maxn = L[N - 1], I = 0;
	for (int i = N - 1; i >= 1; i--) {
		I += C[i];
		long long DD = I - (D - X[i]) * 2LL;
		maxn = max(maxn, DD + L[i - 1]);
	}
	return max(0LL, maxn);
}

int main() {
	cin >> N >> D;
	for (int i = 0; i < N; i++) cin >> X[i] >> C[i];

	long long B1 = solve();

	for (int i = 0; i < N; i++) { if (i < (N - 1 - i)) swap(X[i], X[N - 1 - i]); }
	for (int i = 0; i < N; i++) { if (i < (N - 1 - i)) swap(C[i], C[N - 1 - i]); }
	for (int i = 0; i < N; i++) X[i] = D - X[i];

	long long B2 = solve();
	cout << max(B1, B2) << endl;
	return 0;
}
