#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <thread>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

using namespace std;

int main()
{
	int n; cin >> n;

	vector<int64_t> as(n);
	for (auto& a : as) {
		cin >> a;
	}

	bool has_zero = false;
	int count_minus = 0;
	int64_t min_abs = INT_MAX;
	int64_t sum_abs = 0;

	for (auto& a : as) {
		if (a == 0) has_zero = true;

		if (a < 0) count_minus++;
		sum_abs += abs(a);
		min_abs = min(min_abs, abs(a));
	}

	if (has_zero || (count_minus & 1) == 0) {
		cout << sum_abs << endl;
	}
	else {
		cout << (sum_abs - min_abs * 2) << endl;
	}

	return 0;
}
