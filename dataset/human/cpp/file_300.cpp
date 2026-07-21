#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int r, g, b, n, ans;
	cin >> r >> g >> b >> n;
	ans = 0;
	for (int a = 0; a * r <= n ; a++) {
		for (int d = 0; a * r + d * g <= n ; d++) {
			if ((n -r * a - g * d) % b == 0) {
				ans += 1;
				
			}
		}
	}
	cout << ans;
	return 0;
}
