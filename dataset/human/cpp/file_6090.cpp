#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main()
{
	long long N, C;
	cin >> N >> C;

	vector<long long> x(N);
	vector<long long> v(N);
	auto prev = 0ll;
	for (auto i = 0; i < N; ++i)
	{
		cin >> x[i] >> v[i];
	}

	vector<long long> left;
	vector<long long> right;
	auto maxL = LLONG_MIN;
	auto sumL = 0ll;
	auto maxR = LLONG_MIN;
	auto sumR = 0ll;
	left.push_back(0);
	right.push_back(0);
	for (auto i = 0; i < N; ++i)
	{
		sumL += v[i];
		maxL = max(maxL, sumL - x[i]);
		left.push_back(maxL);

		sumR += v[N - i - 1];
		maxR = max(maxR, sumR - (C - x[N - i - 1]));
		right.push_back(maxR);
	}

	auto result = 0ll;
	sumL = 0;
	sumR = 0;

	for (auto i = 0; i <= N; ++i)
	{
		auto tempL = 0ll;
		auto tempR = 0ll;
		if (i > 0)
		{
			sumL += v[i - 1];
			tempL = sumL - x[i - 1] * 2;
			sumR += v[N - i];
			tempR = sumR - (C - x[N - i]) * 2;
		}

		result = max(result, tempL + right[N - i]);
		result = max(result, tempR + left[N - i]);
	}

	cout << result << endl;

	return 0;
}
