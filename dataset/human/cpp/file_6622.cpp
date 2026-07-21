#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	int open = 0;
	int ans = 1;
	const int MOD = 1e9 + 7;
	for(int i = 1; i <= n; i++) {
		ans = (long long) ans * i % MOD;
	}
	for(auto c : str) {
		int v = c == 'B' ? 1 : 0;
		if((v+open)%2 == 1) {
			//std::cout << "first case\n";
			open++;
		} else if(open > 0) {
			//std::cout << "second case\n";
			ans = (long long) ans * open % MOD;
			open--;
		} else {
			ans = 0;
		}
	}
	if(open != 0) {
		ans = 0;
	}
	std::cout << ans << std::endl;
}
