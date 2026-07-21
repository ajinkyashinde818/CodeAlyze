#include <bits/stdc++.h>

using namespace std;

int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	
	int ans = 0;

	for (int i = 0; i <= n; i += r) {
		for (int j = i; j <= n; j += g) {
			if ((n - j) % b == 0) ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
