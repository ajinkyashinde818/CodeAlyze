#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;

	int pos = 0, zero = 0, neg = 0;

	vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > 0) pos++;
		else if (a[i] == 0) zero++;
		else neg++;
		a[i] = abs(a[i]);
	}
	
	sort(a.begin(), a.end());

	if (neg % 2 == 1 && zero == 0) a[0] = -a[0];

	cout << accumulate(a.begin(), a.end(), 0LL) << endl;

	return 0;
}
