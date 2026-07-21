#include <bits/stdc++.h>

using namespace std;

int main() {
	long n;
	cin >> n;
	vector<long> a(n);
	for (long i=0; i<n; ++i) {
		cin >> a[i];
	}

	long mius_n = 0;
	bool even = false;
	for (long i=0; i<n; ++i) {
		if (a[i]<0) ++mius_n;
		if (a[i] == 0) even = true;
	}
	vector<long> tmp(n);
	for (long i=0; i<n; ++i) {
		tmp[i] = abs(a[i]);
	}
	long dif1_2 = *min_element(tmp.begin(),tmp.end());
	long ans;
	if (mius_n%2 == 0 or even) {
		ans = accumulate(tmp.begin(), tmp.end(), 0l);
	} else {
		ans = accumulate(tmp.begin(), tmp.end(), 0l) - 2*dif1_2;
	}
	cout << ans << endl;
	return 0;
}
