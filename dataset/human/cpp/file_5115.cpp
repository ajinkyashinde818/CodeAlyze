#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cfloat>
#include <climits>
#include <cassert>
#include <random>
#include <bitset>
#include <memory>



int main() {
	int n, r; std::cin >> n >> r;
	if (n >= 10) {
		std::cout << r << '\n';
	}
	else {
		std::cout << r + 100 * (10 - n) << '\n';
	}
}
