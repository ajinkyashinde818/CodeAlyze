#include <iostream>
#include <cstdint>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	std::vector<int64_t> vec(n);
	for (auto&& e : vec)
		std::cin >> e;

	int64_t sum = 0;
	for (auto&& e : vec)
		sum += e;

	int64_t cur = vec[0], ans = std::numeric_limits<int64_t>::max();
	for (int i = 1; i < n; ++i) {
		ans = std::min(ans, std::abs(sum - cur - cur));

		cur += vec[i];
	}

	std::cout << ans << std::endl;
}
