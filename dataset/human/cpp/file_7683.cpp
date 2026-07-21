#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	vector<long long > sum(N);
	sum[0] = a[0];
	for (int i = 1; i < N; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}

	long long ans = (long long)1e14;
	for (int i = 0; i < N - 1; i++) {
		ans = min(ans, abs(sum[i] - (sum[N - 1] - sum[i])));
	}

	cout << ans << endl;

	return 0;
}
