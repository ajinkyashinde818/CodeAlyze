#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	vector<int> a(N);
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	vector<long long> dp(N+1,0);
	long long res = 1000000000;
	for (int i = 0; i < N-1; ++i) {
		dp[i+1] += dp[i] + a[i];
		long long y = sum - dp[i+1];
		if (i == 0) {
			res = abs(dp[i+1]-y);
		}
		else if (abs(dp[i+1]-y) < res) {
			res = abs(dp[i+1]-y);
		}
	}
	cout << res << endl;
	return 0;
}
