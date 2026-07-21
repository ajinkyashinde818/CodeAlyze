#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	int num = 0;
	long long a;
	long long ans = 0, mini = 10000000000;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (a < 0) {
			a = -a;
			num++;
		}
		ans += a;
		mini = min(mini, a);
	}
	if (num % 2 == 1) ans -= 2 * mini;
	cout << ans << endl;

	return 0;
}
