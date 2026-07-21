#include <iostream>
using namespace std;
const int INF = 1001001001;

int main() {
	long long n;
	cin >> n;
	long long sum = 0, absmin = INF, m = 0;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		sum += abs(a);
		if (a < 0) m++;
		if (abs(a) < absmin) absmin = abs(a);
	}
	long long ans = sum;
	if (m & 1) ans -= 2*absmin;
	cout << ans << endl;
	return 0;
}
