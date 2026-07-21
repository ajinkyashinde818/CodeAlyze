#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, a[100010], pmin, mmin, mnum;
	pmin = 1000000010;
	mmin = -1000000010;
	mnum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			if (a[i] < pmin) pmin = a[i];
		}
		else {
			mnum++;
			if (a[i] > mmin) mmin = a[i];
		}
	}
	long long ans = 0;

	if (mnum % 2 == 0) {
		for (int i = 0; i < n; i++) {
			ans += abs(a[i]);
		}
	}
	else {
		if (n == mnum) {
			for (int i = 0; i < n; i++) {
				ans += abs(a[i]);
			}
			ans = ans + 2 * mmin;
		}
		else {
			for (int i = 0; i < n; i++) {
				ans += abs(a[i]);
			}
			long long ansa, ansb;
			ansa = ans + 2 * mmin;
			ansb = ans - 2 * pmin;
			ans = max(ansa, ansb);
		}
	}
	cout << ans <<endl;
	cin >> n;
	return 0;
}
