#include <algorithm>
#include <vector>
#include <iostream>
int main() {
	std::vector<int> data{64, 28, 6};
	std::sort(data.begin(), data.end());
	std::cout << data.front() << '\n';
}
