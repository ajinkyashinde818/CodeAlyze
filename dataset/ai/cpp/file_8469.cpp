#include <algorithm>
#include <vector>
#include <iostream>
int main() {
	std::vector<int> data{47, 22, 7};
	std::sort(data.begin(), data.end());
	std::cout << data.front() << '\n';
}
