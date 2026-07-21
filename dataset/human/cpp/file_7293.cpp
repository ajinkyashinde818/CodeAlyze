#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int32_t N;
	cin >> N;

	vector<int32_t> a(N);
	int64_t total = 0;
	for (int32_t i = 0; i < N; i++) {
		cin >> a[i];
		total += a[i];
	}

	int64_t res = numeric_limits<int64_t>::max();
	int64_t x = 0, y;
	for (int32_t i = 0; i < N - 1; i++) {
		x += a[i];
		y = total - x;
		res = min(res, abs(x - y));
	}

	cout << res << endl;

	return 0;
}
