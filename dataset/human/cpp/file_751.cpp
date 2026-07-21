#include "bits/stdc++.h"

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;

int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	long long ans = 0;
	for (int r = 0; r <= N / R; r++)
		for (int g = 0; g <= (N - R * r) / G; g++)
			if ((N - R * r - G * g) % B == 0)
				ans++;

	cout << ans << endl;
	return 0;
}
