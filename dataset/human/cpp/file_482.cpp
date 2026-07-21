#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
	int r, g, b,n;
	cin >> r >> g >> b>>n;
	int ans = 0;

	for (int i = 0; i<=n /r; i++) {
		for (int j = 0; j<=n /g ; j++) {
			int x = n - (r * i + g * j);
			if (x >= 0 && x % b == 0) {
				ans++;
			}
		}
	}

	cout << ans << endl;

		return 0;
}
