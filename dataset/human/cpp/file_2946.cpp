#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	long long N;
	cin >> N;

	vector<long long> A(N);
	vector<long long> absA(N);
	vector<int> s(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		absA[i] = abs(A[i]);

		if (A[i] > 0)
		{
			s[i] = 0;
		}
		else if (A[i] < 0)
		{
			s[i] = 1;
		}
		else
		{
			s[i] = 2;
		}
	}

	sort(absA.begin(), absA.end());

	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += absA[i];
	}

	for (int i = 0; i < N - 1; i++)
	{
		if (s[i] == 0)
		{
			continue;
		}

		if (s[i + 1] == 2)
		{
			s[i + 1] = 0;
		}
		else
		{
			s[i] = 0;
			s[i + 1] = 1 - s[i + 1];
		}
	}

	if (s[N - 1])
	{
		ans -= absA[0] * 2;
	}

	cout << ans << endl;

	return 0;
}
