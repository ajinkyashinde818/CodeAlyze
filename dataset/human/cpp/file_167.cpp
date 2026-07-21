#include "bits/stdc++.h"
using namespace std;
int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int r = N / R, g = N / G;
	long long ans = 0;
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= g; j++) {
			if ((N - i * R - j * G) % B == 0 && (N - i * R - j * G) / B >= 0) ans++;
		}
	}
	cout << ans << endl;
}
