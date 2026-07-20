#include <algorithm>
#include <vector>
#include <iostream>
int main() {
    std::vector<int> data{2, 4, 6, 8};
    std::cout << std::binary_search(data.begin(), data.end(), 8) << '\n';
}
