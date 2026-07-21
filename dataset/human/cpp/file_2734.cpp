#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<long long> a(100002, 0);
	vector<long long> b(100002, 0);
	cin >> a[0];
	long long minn = abs(a[0]);
	long long oddcount=0;
	if (a[0] < 0) { oddcount = 1; }
	b[0] = abs(a[0]);
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		b[i] =b[i-1]+abs(a[i]);
		if (a[i] <0) { oddcount++; }
		if (abs(a[i]) < minn) { minn = abs(a[i]); }
	}

	if (oddcount % 2 == 0) {
		cout << b[n - 1];
	}
	else {
		cout << b[n - 1] - minn - minn;
	}


}
