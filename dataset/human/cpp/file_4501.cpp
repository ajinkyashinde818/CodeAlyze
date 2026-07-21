#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(10);

	int t, d, ta, tb, da, db;
	cin >> t >> d >> ta >> tb >> da >> db;

	double ans = DBL_MAX;
	for(int va = 0; va <= d; va += da) {
		for(int vb = (va ? 0 : db); va + vb <= d; vb += db) {
			ans = min(ans, abs(t - static_cast<double>(ta * va + tb * vb) / (va + vb)));
		}
	}

	cout << ans << endl;

	return EXIT_SUCCESS;
}
