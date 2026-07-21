#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <numeric>
#include <algorithm>
#include <functional>

#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<long long> a(N, 0);

	long long left_sum = 0;
	long long right_sum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		right_sum += a[i];
	}

	left_sum += a[0];
	right_sum -= a[0];

	long long min_diff = abs(left_sum - right_sum);

	for (int i = 1; i < N - 1; i++)
	{
		left_sum += a[i];
		right_sum -= a[i];

		min_diff = min(min_diff, abs(left_sum - right_sum));
	}

	cout << min_diff;

	return 0;
}
