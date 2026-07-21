#include <iostream>
#include <vector>
#include <cstdint>

using Int = std::int64_t;

constexpr Int Mod = 1e9 + 7;

int main() {
	Int n;
	std::cin >> n;

	Int ans = 1;
	Int depth = 0;
	for (int i = 0; i < 2 * n; ++i) {
		char c;
		std::cin >> c;

		const Int cur = (c == 'B');

		if ((depth + cur) % 2 == 1) {
			++depth;
			ans = (ans * depth) % Mod;
		}
		else
			--depth;

		if (depth < 0) {
			ans = 0;
			break;
		}
	}
	if (depth != 0)
		ans = 0;

	for (int i = 2; i <= n; ++i)
		ans = (ans * i) % Mod;

	std::cout << ans << std::endl;
}
