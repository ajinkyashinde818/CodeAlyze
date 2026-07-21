#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int r, g, b, n;
	std::cin >> r >> g >> b >> n;
	int ans = 0;
	for(int i = 0; i * r <= n; i++) {
		for(int j = 0; i * r + j * g <= n; j++) {
			if((n - i * r - j * g) % b == 0) {
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
}
