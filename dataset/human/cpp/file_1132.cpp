#include <iostream>

using namespace std;

int main()
{
	int r, g, b, n;
	cin >> r >> g >> b >> n;

	int ans = 0;
	for (int i = 0; i <= n; i+=r) {
		for (int j = 0; i + j <= n; j+=g) {
			if ((n - i - j) % b == 0) {
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
