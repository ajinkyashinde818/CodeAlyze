#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string str;
	cin >> str;

	ll res = 1;
	ll as = 0;
	for (int i = 0; res && i < 2*n; ++i) {
		int c = 2*n-i; // Number of flips assuming it's a B
		if ((c & 1) == (str[i] == 'B')) {
			// It's a B
			res = (res * as) % MOD;
			--as;
		} else {
			// It's a A
			++as;
		}
	}
	if (as != 0) res = 0;
	for (int i = 1; i <= n; ++i) res = (res * i) % MOD; // order of operations
	cout << res << '\n';

}
