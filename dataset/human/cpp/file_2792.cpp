#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;

	vector <ll> a(n);

	ll min = 1e10;

	int cnt = 0;
	ll sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += abs(a[i]);

		if (min > abs(a[i]))
			min = abs(a[i]);

		if (a[i] < 0)
			cnt++;
	}

	if (cnt % 2 != 0)
		sum -= 2 * min;



	cout << sum << endl;
	
	return 0;
}
