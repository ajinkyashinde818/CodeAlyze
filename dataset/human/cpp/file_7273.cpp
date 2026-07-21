#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	long long int n, i, j, x;
	vector<long long int>a;

	cin >> n;

	cin >> i;
	a.push_back(i);
	for (i = 1; i < n; i++) {
		cin >> j;
		a.push_back(j + a[i - 1]);
	}

	x = -1;
	for (i = 0; i < n-1; i++) {
		j = abs(2 * a[i] - a[n - 1]);
		if (x > j || x == -1)
			x = j;
	}

	cout << x;

	return 0;
}
