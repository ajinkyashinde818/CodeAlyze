#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int R, G, B, N; cin >> R >> G >> B >> N;
	int ans = 0;
	int rNum = ceil(N / R);
	int gNum = ceil(N / G);
	int bNum = ceil(N / B);
	for (int r = 0; r <= rNum; r++) {
		for (int g = 0; g <= gNum; g++) {
			int tmp = N - r * R - g * G;
			if (tmp < 0) continue;
			if (tmp % B != 0) continue;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
