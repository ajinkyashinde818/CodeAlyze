#include <bits/stdc++.h>
using namespace std;

signed main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;

	int cnt = 0;

	for (int i = 0; i * r <= n; ++i) {
		for (int j = 0; i * r + j * g <= n; ++j) {
			int ex = n - i * r - j * g;
			if (ex > 0 and ex % b == 0 or ex == 0) cnt++;
		}
	}

	cout << cnt << endl;
}
