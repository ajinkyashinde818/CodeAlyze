// B - RGB Boxes

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	ll ans = 0;

	for (int r=0; r*R <= N; r++) {
		for (int g=0; r*R + g*G <= N; g++) {
			if ((N - r*R - g*G) % B == 0) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
