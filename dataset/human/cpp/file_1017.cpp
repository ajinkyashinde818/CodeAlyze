#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <cmath>

using namespace std;
using lli = long long int;

//int main(void) {
//	lli N,ans = 0;
//	cin >> N;
//
//	if (N == 1) {
//		cout << "0" << endl;
//		return 0;
//	}
//
//	for (lli i = 1; i <= sqrt(N); i++) {
//		lli m = (N - i) / i;
//
//		if (N % m == N / m) {
//			ans += m;
//		}
//
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}
//
//int main(void) {
//
//	lli N,ans = 0;
//	cin >> N;
//
//	lli a = 0, b = 0;
//
//	for (int i = 0; i < N; i++) {
//		string str;
//		cin >> str;
//		if (str[0] == 'B') b++;
//		if (str[str.size() - 1] == 'A') a++;
//		for (int j = 0; j < str.size() - 1; j++) {
//			if (str[j] == 'A' && str[j + 1] == 'B') {
//				ans++;
//			}
//		}
//	}
//
//	cout << ans + min(a, b) << endl;
//
//	return 0;
//}

int main(void) {

	lli r, g, b, n, ans = 0;
	cin >> r >> g >> b >> n;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if ((n - r * i - g * j) >= 0 && (n - r * i - g * j) % b == 0) {
				ans++;
				//cout << r << " " << g << " " << (n - r * i - g * j) / b << endl;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
