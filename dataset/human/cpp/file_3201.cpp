#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <tuple>
#include <regex>
#include <map>

using namespace std;
using ull = unsigned long long;
using ll = long long;

ll gcd(ll a, ll b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int main() {
	int N;
	cin >> N;

	vector<ll> vec(N);

	for (size_t i = 0; i < N; i++) {
		cin >> vec[i];
	}

	// まずは絶対値の合計を求める
	ll ans = accumulate(cbegin(vec), cend(vec), 0LL, [](auto sum, auto x) {
		return sum + abs(x);
	});


	// 0があれば合計が正解
	{
		auto it = find(cbegin(vec), cend(vec), 0);
		if (it != cend(vec)) {
			cout << ans << endl;
			return 0;
		}
	}
	// 0なしのとき・・・
	// 0なしでも、負の数が偶数個であれば合計で行ける
	// 奇数個だと最低の要素のみが負だと考えればよい

	auto minuscount = count_if(cbegin(vec), cend(vec), [](auto x) {
		return x < 0;
	});

	if (minuscount % 2 == 1) {
		// 全部を絶対値にする
		for_each(begin(vec), end(vec), [](auto&& x) {
			x = abs(x);
		});

		const auto elem = *min_element(cbegin(vec), cend(vec));
		ans -= elem * 2;
	}

	cout << ans << endl;
	return 0;
}
