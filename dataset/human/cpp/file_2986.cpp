#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long int a[n];
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long int neg = 0, min = abs(a[0]), sum = 0, zero = 0;
	for (i = 0; i < n; i++) {
		if (a[i] < 0)
			neg++;
		if (a[i] == 0)
			zero = 1;
		if (abs(a[i]) < min)
			min = abs(a[i]);
		sum += abs(a[i]);
	}
	if (neg % 2 == 1 && zero == 0)
		sum -= min * 2;
	cout << sum;
	return 0;
}
