#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	vector<long long> a(n);
	long long s = 0;
	for (auto&& ai : a)
	{
		cin >> ai;
		s += ai;
	}
	long long s1 = a[0];
	long long s2 = s - s1;
	long long mind = abs(s1 - s2);
	for (int i = 1; i < n-1; i++)
	{
		s1 += a[i];
		s2 -= a[i];
		mind = min(mind, abs(s1 - s2));
	}
	cout << mind << endl;
	return 0;
}
