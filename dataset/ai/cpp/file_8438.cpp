#include <algorithm>
#include <vector>
#include <iostream>
int main() {
    std::vector<int> data{16, 22, 4};
    std::sort(data.begin(), data.end());
    std::cout << data.front() << '\n';
}
