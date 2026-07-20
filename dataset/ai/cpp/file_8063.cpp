#include <algorithm>
#include <vector>
#include <iostream>
int main() {
    std::vector<int> data{86, 19, 7};
    std::sort(data.begin(), data.end());
    std::cout << data.front() << '\n';
}
