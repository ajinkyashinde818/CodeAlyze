#include<iostream>
using namespace std;
int main()
{
	int r, g, b, n;
	int R, G, B;
	int left, mid, ans = 0;
	int i, j;
	cin >> r >> g >> b >> n;

	for (left = 0; left <= n; left++) {
		for (mid = 0; left+mid <= n; mid++) {
			R = left;
			G = mid;
			B = n - left - mid;
			if (R%r == 0 && G%g == 0 && B%b == 0) {
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;

}
