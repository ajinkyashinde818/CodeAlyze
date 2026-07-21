#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

int main(void) {
	// input
	int n;
	std::cin >> n;
	std::vector<long long> a(n);
	for(int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	// count minus signs
	int n_minus = 0;
	for(int i = 0; i < n; ++i) {
		n_minus += (a[i] < 0LL ? 1 : 0);
	}
	n_minus %= 2;
	
	// zero ?
	for(int i = 0; i < n; ++i) {
		if(a[i] == 0LL) n_minus = 0;
	}

	// abs
	std::vector<long long> abs_a(n);
	for(int i = 0; i < n; ++i) {
		abs_a[i] = std::abs(a[i]);
	}
	std::sort(abs_a.begin(), abs_a.end());

	long long sum_b = 0;
	if(n_minus == 0) sum_b = std::accumulate(abs_a.begin(), abs_a.end(), 0LL);
	else sum_b = std::accumulate(abs_a.begin(), abs_a.end(), 0LL) - (2 * abs_a[0]);

	std::cout << sum_b << std::endl;

	return 0;
}
