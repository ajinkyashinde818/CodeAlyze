#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main(int argc, char const *argv[]) {
	int n;
	std::cin >> n;
	int num_minus = 0;
	std::vector<ll> v(n);
	for (size_t i = 0; i < v.size(); i++) {
		std::cin >> v[i];
		if (v[i] < 0) {
			num_minus++;
		}
	}

	ll vmin = abs(v[0]);
	ll ans = 0;
	for (size_t i = 0; i < v.size(); i++) {
		ans += abs(v[i]);
		vmin = min(vmin, abs(v[i]));
	}

	if (num_minus % 2 == 0) {
		std::cout << ans << '\n';
	}
	else {
		std::cout << ans - 2 * vmin << '\n';
	}


	return 0;
}
