#include <iostream>
using namespace std;

int main(void) {
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int ans = 0;
	for (int i = 0; i <= N / R; ++i) {
		for (int j = 0; j <= N - (i * R); j += G) {
			int b_cnt = N - (i * R) - j;
			if (b_cnt % B == 0)
				++ans;
		}
	}

	cout << ans << '\n';
	return 0;
}
