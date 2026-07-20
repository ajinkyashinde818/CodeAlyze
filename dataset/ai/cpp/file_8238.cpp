#include <algorithm>
#include <vector>
#include <iostream>
int main() {
    std::vector<int> data{83, 8, 7};
    std::sort(data.begin(), data.end());
    std::cout << data.front() << '\n';
}
