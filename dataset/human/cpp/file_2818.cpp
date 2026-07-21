#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long k = 0, mn = 1e9, sum = 0;
vector <int > a;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mn = min(mn, (long long)abs(a[i]));
		if (a[i] < 0)
			k++;
		sum += abs(a[i]);
	}
	sum -= mn;
	if (k % 2 == 1)
		mn *= (-1);
	sum += mn;
	cout << sum;
	return 0;
}
