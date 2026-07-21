#include <iostream>
#include <algorithm>
using namespace std;

int dp[209][209];

int main() {
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			int px = j, py = i - j; // (黒石, 白石)

			int col[300]; for (int k = 0; k < 300; k++) col[k] = 0;
			if (px >= 1) col[dp[px - 1][py + 1]] = 1;
			if (py >= 1) col[dp[px][py - 1]] = 1;
			for (int k = 1; k <= min(px, py); k++) col[dp[px - k][py]] = 1;

			for (int k = 0; k < 300; k++) {
				if (col[k] == 0) { dp[px][py] = k; break; }
			}
		}
	}

	int Q, W, B, X = 0; cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> W >> B;
		X ^= dp[B][W];
	}
	if (X >= 1) cout << "0" << endl;
	else cout << "1" << endl;
	return 0;
}
