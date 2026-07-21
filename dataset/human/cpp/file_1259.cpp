#include <bits/stdc++.h>
using namespace std;

int main()
{
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int res = 0;
	for (int r = 0; r <= N; r += R) {
		for (int g = 0; g <= N; g += G) {
			int b = N - r - g;
			res += (0 <= b && b % B == 0);
		}
	}
	cout << res << endl;
	return 0;
}
