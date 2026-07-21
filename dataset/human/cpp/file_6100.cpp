#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

LL N, C;
pair<LL, LL>sus[123456];

LL solve() {
	vector<LL>flip(1);
	LL cal = 0;
	for (int i = N - 1; i >= 0; --i) {
		cal += sus[i].second;
		flip.push_back(cal - 2 * (C - sus[i].first));
		flip.back() = max(flip.back(), flip[flip.size() - 2]);
	}
	vector<LL>go(1);
	LL cas = 0;
	for (int i = 0; i < N; ++i) {
		cas += sus[i].second;
		go.push_back(cas - (sus[i].first));
		go.back() = max(go.back(), go[go.size() - 2]);
	}
	LL ans = 0;
	for (int i = 0; i <= N; ++i) {
		ans = max(ans, flip[i] + go[N - i]);
	}
	//cout << ans << endl;
	return ans;
}

int main(void)
{
	cin >> N >> C;
	for (int i = 0; i < N; ++i) {
		cin >> sus[i].first >> sus[i].second;
	}
	LL ans = solve();
	for (int i = 0; i < N; ++i) {
		sus[i].first = C - sus[i].first;
	}
	sort(sus, sus + N);
	LL can = solve();
	cout << max(ans, can) << endl;
	return 0;
}
