#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long>A(N);
	long long x = 0;
	long long y = 0;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		y += A[i];
	}
	long long ans = 1e18;
	for (int i = 0; i < N - 1; ++i) {
		x += A[i];
		y -= A[i];
		ans = min(ans, abs(x - y));
	}
	cout << ans << endl;
	return 0;
}
