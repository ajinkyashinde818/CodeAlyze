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

	vector<long long> A(N, 0);
	int minus_cnt = 0;
	long long accum = 0;
	long long min_abs_a = 1e9;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];

		if (A[i] < 0) minus_cnt++;

		long long abs_a = abs(A[i]);
		accum += abs_a;
		min_abs_a = min(min_abs_a, abs_a);
	}

	if (minus_cnt % 2 == 0)
	{
		cout << accum;
	}
	else
	{
		cout << accum - 2 * min_abs_a;
	}

	return 0;
}
