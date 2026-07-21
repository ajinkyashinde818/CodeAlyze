#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
#include <vector>
#include <math.h>
#include <string>
#include <queue>

using namespace std;


int main()
{
	int N;
	cin >> N;

	int mnum = 0;
	int absmin = 1000000001;
	long long sum = 0;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		if (a < 0)
		{
			mnum++;
		}
		a = abs(a);
		absmin = min(absmin, a);

		sum += a;
	}

	if (mnum % 2 == 1)
	{
		sum -= 2 * absmin;
	}

	cout << sum << endl;

	return 0;
}
