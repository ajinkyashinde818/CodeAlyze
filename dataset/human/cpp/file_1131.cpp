#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int ans = 0;
	for (int r = 0; r <= N; r += R) {
		for (int g = 0; g + r <= N; g += G) {
			int rest = N - r - g;
			if (rest < 0 || rest % B != 0) {
				continue;
			}
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
