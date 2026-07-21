#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n ;
	vector<long long> a(n, 0);
	vector<long long> b(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0) {
			b[i] = b[i-1]+a[i];
		}
		else { b[i] = a[i]; }
	}
	long long minn = INT64_MAX;
	for (int i = 0; i < n-1; i++) {
		minn = min(minn, abs(b[i] - (b[n - 1] - b[i])));
	}



	cout << minn<< endl;
}
