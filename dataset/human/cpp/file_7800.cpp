#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

int main()
{
	long N;
	long ans = LONG_MAX;
	cin >> N;

	vector<int> A(N);
	vector<long> subSum(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];

		if (i > 0)
			subSum[i] = subSum[i - 1] + A[i];
		else
			subSum[i] = A[i];
	}

	long sum = subSum[N - 1];
	for (int i = 0; i < N - 1; i++)
	{
		long num = abs(subSum[i] - (sum - subSum[i]));
		if (ans > num)
			ans = num;
	}

	cout << ans << endl;

	return 0;
}
