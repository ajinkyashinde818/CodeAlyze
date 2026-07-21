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
	vector<int> a(n);
	vector<int> b(n);
	for (auto &t : a) {
		cin >> t;
	}
	for (auto &t : b) {
		cin >> t;
	}
	auto check = [&]() {
		int ok = 1;
		for (int i = 0; i < n; i++) {
			ok &= (a[i] != b[i]);
		}
		if (ok) {
			cout << "Yes\n";
			for (auto t : b) {
				cout << t << ' ';
			}
			cout << '\n';
			exit(0);
		}
	};
	check();
	reverse(b.begin(), b.end());
	check();
	vector<int> good;
	vector<int> bad;
	int some = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			bad.push_back(i);
			some = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i] && a[i] != some && b[i] != some) {
			good.push_back(i);
		}
	}
	if (bad.size() > good.size()) {
		cout << "No" << '\n';
	} else {
		for (int i = 0; i < (int)bad.size(); i++) {
			swap(b[bad[i]], b[good[i]]);
		} 
		check();
		cout << "No\n";
	}
}
