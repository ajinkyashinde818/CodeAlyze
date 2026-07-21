#include<bits/stdc++.h>
//#define int long long
using namespace std;

signed main() {
	long long ans = 0;
	int r, g, b;
	int n;
	cin >> r >> g >> b >> n;
	for (int i = 0; i < 3001; ++i) {
		for (int j = 0; j < 3001; ++j) {
			int res = n - (r * i + g * j);
			if (res >= 0 && res % b == 0)++ans;
		}
	}
	cout << ans << endl;
}
