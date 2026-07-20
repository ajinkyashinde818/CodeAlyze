#include <algorithm>
#include <vector>
#include <iostream>
int main() {
    std::vector<int> data{46, 10, 9};
    std::sort(data.begin(), data.end());
    std::cout << data.front() << '\n';
}
