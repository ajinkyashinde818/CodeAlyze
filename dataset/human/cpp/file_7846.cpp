#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>

using sll = signed long long;

int main() {

	sll n;
	std::cin >> n;

	std::vector<sll> v;
	v.resize(n);

	sll max_{};

	for (auto&e : v) {
		std::cin >> e;
		max_ += e;
	}
//	max_*= -1;

	sll t{}, ans{std::numeric_limits<sll>::max()};
	for (int i{0}; i < n-1; ++i) {

		t += v[i];
		max_ -= v[i];
//		std::cout << t << " " << max_ << "\n";
		ans = std::min(ans, std::abs(max_ - t) );
	}
	std::cout << ans << "\n";
	return 0;
}
