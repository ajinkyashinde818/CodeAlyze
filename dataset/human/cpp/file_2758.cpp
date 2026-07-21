#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <complex>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main()
{
	int n;
	std::cin >> n;

	vector<ll> a((int)n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	ll sum = 0;
	ll minVal = 0;
	ll count = 0;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] < 0)
		{
			++count;
			a[i] *= -1;
		}

		sum += a[i];

		if (i == 0) minVal = a[i];
		else minVal = min(a[i], minVal);
	}

	ll ans = 0;
	if (count % 2 == 0)
	{
		ans = sum;
	}
	else
	{
		ans = sum - 2 * minVal;
	}
	cout << ans << endl;
}
