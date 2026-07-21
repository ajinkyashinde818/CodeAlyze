#include <iostream>

int main() {
	int r, g, b, n;
	std::cin >> r >> g >> b >> n;
	int ans = 0;
	for (int nr = 0; nr <= n; ++nr) {
		for (int ng = 0; ng <= n; ++ng) {
			int left = (n - nr * r - ng * g);
			if (left >= 0 && left % b == 0)
				++ans;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
