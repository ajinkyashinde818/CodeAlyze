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
	int N;
	cin >> N;
	vector<long long> a(N);
	auto sum = 0ll;
	for (auto i = 0; i < N; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	auto temp = 0ll;
	auto result = LLONG_MAX;
	for (auto i = 0; i < N - 1; ++i)
	{
		temp += a[i];
		sum -= a[i];
		result = min(result, abs(temp - sum));
	}

	cout << result << endl;

	return 0;
}
