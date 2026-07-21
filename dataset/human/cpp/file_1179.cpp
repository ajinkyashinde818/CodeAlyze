#include <iostream>
using namespace std;

int r, g, b, n, ans;

int main() {
	cin >> r >> g >> b >> n;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) {
			if (r * i + b * j > n)
				break;
			int k = n - r * i - b * j;
			ans += (k % g == 0);
		}
	cout << ans;
}
