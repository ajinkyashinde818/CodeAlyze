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
using namespace std;


int main()
{
	int N;
	cin >> N;
	vector<long long> A(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	long long prev[2] = { A[0], -A[0] };
	long long next[2];

	for (auto i = 1; i < N - 1; ++i)
	{
		next[0] = max(prev[0] + A[i], prev[1] - A[i]);
		next[1] = max(prev[0] - A[i], prev[1] + A[i]);

		swap(prev, next);
	}

	cout << max(prev[0] + A[N - 1], prev[1] - A[N - 1]) << endl;

	return 0;
}
