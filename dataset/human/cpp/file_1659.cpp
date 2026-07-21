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
#include <chrono>
#include <random>
#include <functional>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int k = 2; k * (k - 1) / 2 <= n; k++) {
		if (k * (k - 1) / 2 == n) {
			cout << "Yes\n";
			cout << k << endl;
			vector<vector<int>> ans(k);
			int c = 0;
			for (int i = 0; i < k; i++) {
				for (int j = i + 1; j < k; j++) {
					ans[i].push_back(c);
					ans[j].push_back(c);
					c++;
				}
			}
			for (auto t : ans) {
				cout << t.size() << ' ';
				for (auto x : t) {
					cout << x + 1 << ' ';
				}
				cout << '\n';
			}
			return 0;
		}
	}
	cout << "No\n";
}
