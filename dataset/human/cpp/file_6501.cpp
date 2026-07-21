#include <iostream>
#include <set>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	const int64_t MOD = 1000000007;
	//vector<vector<int64_t>> cnt(2*n + 1, vector<int64_t>(n+1,0));
	vector<int64_t> cnt(2*n+1,0);
	cnt[0] = 1;
	int64_t cont = 0;
	//cnt[0][0] = 1;
	for (int i = 0; i < 2*n; ++i) {
		char cc = s[i];
		int c = 0;
		if (cc == 'W') {
			c = 0;
		}
		else {
			c = 1;
		}
		int64_t j = cont;
		if (c == j % 2) {
			// close
			if (j > 0) {
				cnt[i + 1] += cnt[i] * j;
				cnt[i + 1] %=MOD;
				cont -= 1;
			}
			else {
				cout << 0 << endl;
				return 0;
			}
		}
		else {
			// open
			if (j < n) {
				cnt[i + 1] += cnt[i];
				cnt[i + 1] %= MOD;
				cont += 1;
			}
			else {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	if (cont != 0) {
		cout << 0 << endl;
		return 0;
	}
	int64_t ord = cnt[2*n];
	for (int i = 1; i <= n; i++) {
		ord *= i;
		ord %= MOD;
	}
	cout << ord << endl;
}
