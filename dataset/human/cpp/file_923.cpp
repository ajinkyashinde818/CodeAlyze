#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, g, b, n, cnt;
	cnt = 0;
	cin >> r >> g >> b >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (((n - i*r - g*j) % b == 0) and (n - i*r - g*j >= 0)) cnt += 1;
		}
	}
	cout << cnt << endl;
	return 0;
}
