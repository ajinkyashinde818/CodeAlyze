#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);

	int minNum = INT_MAX, minIdx = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		if (abs(A[i]) < minNum)
		{
			minNum = abs(A[i]);
			minIdx = i;
		}
	}

	for (int i = 0; i < minIdx; ++i)
	{
		if (A[i] < 0)
		{
			A[i] = -A[i];
			A[i + 1] = -A[i + 1];
		}
	}
	for (int i = N - 1; i > minIdx; --i)
	{
		if (A[i] < 0)
		{
			A[i] = -A[i];
			A[i - 1] = -A[i - 1];
		}
	}

	long long int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		ans += A[i];
	}

	cout << ans << endl;

	return 0;
}
