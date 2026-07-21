#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <tuple>
#include <numeric>
#include <queue>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <regex>
#include <stack>
#include <limits>

using namespace std;

map<int, int> readToMap(int n) {
	map<int, int> res;
	for (int i = 0; i < n; ++i) {
		int j;
		cin >> j;
		res[j]++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n; 
	map<int, int> a = readToMap(n);
	map<int, int> b = readToMap(n);

	typedef pair<int, int> item;
	priority_queue<item> q;
	for (auto& it : a) {
		if (b.count(it.first) > 0) {
			q.push({it.second + b[it.first], it.first});
		}
	}

	vector<pair<int, int>> res;
	while (!q.empty()) {
		int cnt, num;
		tie(cnt, num) = q.top(); q.pop();
		if (cnt > n) { cout << "No\n"; return 0; }
		if (!q.empty()) {
			int num2, cnt2;
			tie(cnt2, num2) = q.top(); q.pop();
			a[num]--;
			b[num2]--;
			res.emplace_back(num, num2);
			if (a[num] != 0) {
				q.push({ cnt - 1, num });
			} else {
				a.erase(num);
			}

			if (b[num2] != 0) {
				q.push({ cnt2 - 1, num2 });
			} else {
				b.erase(num2);
			}
		} else {
			auto it = begin(b);
			if (it->first == num) {
				++it;
			}
			int num2 = it->first;
			a[num]--;
			b[num2]--;
			res.emplace_back(num, num2);
			if (a[num] != 0) {
				q.push({ cnt - 1, num });
			} else {
				a.erase(num);
			}

			if (b[num2] == 0) {
				b.erase(num2);
			}
		}
	}

	int c = res.size();
	for (auto& it : a) {
		for (int i = 0; i < it.second; ++i) {
			res.emplace_back(it.first, 0);
		}
	}

	for (auto& it : b) {
		for (int i = 0; i < it.second; ++i) {
			res[c].second = it.first;
			++c;
		}
	}

	sort(begin(res), end(res));
	cout << "Yes\n";
	for (int i = 0; i < n; ++i) {
		cout << res[i].second << ' ';
	}
	cout << endl;

	return 0;
}
