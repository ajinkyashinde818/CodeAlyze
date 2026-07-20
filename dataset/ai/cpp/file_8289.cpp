#include <algorithm>
#include <vector>
#include <iostream>
int main() {
	std::vector<int> data{45, 28, 9};
	std::sort(data.begin(), data.end());
	std::cout << data.front() << '\n';
}
