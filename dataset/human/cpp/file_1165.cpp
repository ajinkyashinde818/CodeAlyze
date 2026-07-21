#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int  x = 0, f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int ans = 0;
	for (int i = 0; i * r <= n; ++ i) {
		for (int j = 0; j * g + i * r <= n; ++ j) {
			if ((n - j * g - i * r) % b == 0) ++ ans;
		}
	}
	cout << ans;
	return 0;
}
