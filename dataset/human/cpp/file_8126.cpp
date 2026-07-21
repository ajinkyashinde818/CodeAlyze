#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long long> a(n);
	cin >> a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	long long mn = 101010101010101010;
	for (int i = 0; i < n - 1; i++) {
		mn = min(mn, abs(a[n - 1] - a[i] - a[i]));
	}
	cout << mn << endl;

	return 0;
}
