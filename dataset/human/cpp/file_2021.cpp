#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>

int main() {
	int N;
	std::cin >> N;

	int numNeg = 0;
	int minAbs = std::numeric_limits<int>::max();
	long long result = 0;
	for(int i = 0; i < N; i++) {
		int a;
		std::cin >> a;
		if(a < 0) {
			numNeg++;
		}

		const int aa = std::abs(a);
		result += aa;
		minAbs = std::min(aa, minAbs);
	}

	if(numNeg % 2 != 0) {
		result -= minAbs * 2;
	}

	std::cout << result << std::endl;

	return 0;
}
