#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int red = N / R, ans = 0;
	for(; red >= 0; red--) {
		int green = (N - red * R) / G;
		for(; green >= 0; green--) {
			if((N - red * R - green * G) % B == 0) ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
