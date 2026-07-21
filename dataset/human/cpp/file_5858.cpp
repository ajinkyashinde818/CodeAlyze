#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, C, SUM[100010] = {}, ANS = 0, MAX;
	static pair<long long, long long> P[100010];
	cin >> N >> C;
	P[0] = { 0, 0 };
	for (int i = 1; i <= N; i++) {
		long long X, V;
		cin >> X >> V;
		P[i] = { X, V };
		SUM[i] = SUM[i - 1] + V;
	}
	for (int i = 1; i <= N; i++) {
		ANS = max(ANS, SUM[i] - P[i].first);
	}
	for (int i = N; i >= 1; i--) {
		ANS = max(ANS, (SUM[N] - SUM[i - 1]) - (C - P[i].first));
	}
	MAX = 0;
	for (int i = 1; i <= N; i++) {
		ANS = max(ANS, (SUM[N] - SUM[i - 1]) - (C - P[i].first) + MAX);
		MAX = max(MAX, SUM[i] - P[i].first * 2);
	}
	MAX = 0;
	for (int i = N; i >= 1; i--) {
		ANS = max(ANS, SUM[i] - P[i].first + MAX);
		MAX = max(MAX, (SUM[N] - SUM[i - 1]) - (C - P[i].first) * 2);
	}
	cout << ANS;
}
