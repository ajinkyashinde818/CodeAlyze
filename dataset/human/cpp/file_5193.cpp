#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <queue>
#include <unordered_map>

int main() {
	int32_t n, displayed;
	std::cin >> n >> displayed;
	if(n >= 10)
		std::cout << displayed;
	else
		std::cout << displayed + 100 * (10 - n);
	return 0;
}
