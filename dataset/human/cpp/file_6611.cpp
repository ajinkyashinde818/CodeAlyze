#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int mul(int a, int b) {
	return (a * b) % MOD; 
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//1110
	//0111
	//
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt_op = 0;
	int ans = 1;
	vector<int> t;
	for (int i = 0; i < 2 * n; i++) {
		if ((cnt_op % 2) == (s[i] == 'W')) {
			cnt_op++;
		} else {
			if (cnt_op <= 0) {
				cout << 0 << endl;
				exit(0);
			}
			ans = mul(ans, cnt_op);
			cnt_op--;
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = mul(ans, i);
	}
	if (cnt_op != 0) {
		ans = 0;
	}
	cout << ans << endl;
	// for (auto x : t) {
	// 	cerr << x;
	// }
	// cerr << endl;
}
