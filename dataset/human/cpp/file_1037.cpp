#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include "boost/multiprecision/cpp_int.hpp"

using ll = long long;
using ull = unsigned long long;
namespace mp = boost::multiprecision;

int main() {

	std::cin.tie(nullptr); std::ios::sync_with_stdio(false);

	int R, G, B, N; std::cin >> R >> G >> B >> N;

	int ans = 0;

	for (int r = 0; r <= 3000; r++) {
		for (int g = 0; g <= 3000; g++) {
			int tmp = N - r * R - g * G;
			if (tmp >= 0 && tmp % B == 0)ans++;
		}
	}

	std::cout << ans;

	return 0;

}
