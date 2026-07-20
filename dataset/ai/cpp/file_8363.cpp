#include <algorithm>
#include <vector>
#include <iostream>
int main() {
    std::vector<int> data{30, 9, 6};
    std::sort(data.begin(), data.end());
    std::cout << data.front() << '\n';
}
