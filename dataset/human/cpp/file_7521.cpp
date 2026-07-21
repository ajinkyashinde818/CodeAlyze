#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> a(N);

	for (auto &x : a) {
		cin >> x;
	}

	const auto T = accumulate(a.begin(), a.end(), 0LL);

	long long ans = 1LL << 60;

	long long s = 0;
	for (int i = 0; i + 1 < N; ++i) {
		s += a[i];
		ans = min(ans, abs(s - (T - s)));
	}
	cout << ans << endl;
}
