#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <map>

int main() {
	long long n, r;

	std::cin >> n >> r;

	if (n >= 10) {
		std::cout << r << std::endl;
	}
	else {
		std::cout << r + 100 * (10 - n) << std::endl;
	}

	return 0;
}
