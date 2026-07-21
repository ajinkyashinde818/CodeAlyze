#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<int, P> E;
const LL MOD = 1000000007LL;
LL x[100000];
LL v[100000];
LL maxA[100000];
LL maxB[100000];
int main() {
	int N;
	LL C;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> v[i];
	}
	LL sum = 0;
	for (int i = 0; i < N; i++) {
		sum += v[i];
		maxA[i] = sum - x[i];
	}
	for (int i = 1; i < N; i++) maxA[i] = max(maxA[i], maxA[i - 1]);
	sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		sum += v[i];
		maxB[i] = sum - (C - x[i]);
	}
	for (int i = N - 2; i >= 0; i--) maxB[i] = max(maxB[i], maxB[i + 1]);
	LL ans = 0;
	ans = max(ans, max(maxA[N - 1], maxB[0]));
	for (int i = 0; i + 1 < N; i++) {
		ans = max(ans, maxA[i] + maxB[i + 1] - x[i]);
	}
	for (int i = N - 1; i > 0; i--) {
		ans = max(ans, maxB[i] + maxA[i - 1] - (C - x[i]));
	}
	cout << ans << endl;
}
