#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	int R, G, B, n;
	cin >> R >> G >> B >> n;
	int ans = 0;
	for (int r = 0; r * R <= n; r++)
		for (int g = 0; g * G + r * R <= n; g++) {
			int rem = n - r * R - g * G;
			if (rem % B != 0 || rem < 0) continue;
//			cout << r << " " << g << " " << rem / B << endl;
			ans++;
		}
	cout << ans << endl;


	return 0;
}
