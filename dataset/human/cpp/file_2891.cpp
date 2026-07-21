#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	bool isZero = false;
	int countMinus = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			isZero = true;
		}
		else if (a[i] < 0) {
			countMinus++;
			a[i] *= -1;
		}
		ans += a[i];
	}
	if (isZero || countMinus % 2 == 0) {
		cout << ans << endl;
	}
	else {
		sort(a.begin(), a.end());
		cout << ans - a[0] * 2 << endl;
	}






	return 0;
}
