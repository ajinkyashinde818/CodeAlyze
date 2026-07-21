#include<iostream>
#include<vector>
#include <algorithm>

int main()
{
	int N;
	std::vector<int> As;

	std::cin >> N;

	int num_minus = 0;
	for (int i = 0; i < N; ++i) {
		int A;
		std::cin >> A;
		As.push_back(A);

		if (A < 0) {
			++num_minus;
		}
	}
	long sum = 0;
	if (num_minus % 2 == 0) {
		for (int i = 0; i < N; ++i) {
			sum += std::abs(As[i]);
		}
	}
	else {
		std::vector<int> As_abs;
		for (int i = 0; i < N; ++i) {
			const int A_abs = std::abs(As[i]);
			sum += A_abs;
			As_abs.push_back(A_abs);
		}

		int min = *std::min_element(As_abs.begin(), As_abs.end());
		sum -= 2 * min;
	}
	std::cout << sum;

	return 0;
}
