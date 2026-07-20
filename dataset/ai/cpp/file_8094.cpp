#include <algorithm>
#include <vector>
#include <iostream>
int main() {
	std::vector<int> data{28, 19, 3};
	std::sort(data.begin(), data.end());
	std::cout << data.front() << '\n';
}
