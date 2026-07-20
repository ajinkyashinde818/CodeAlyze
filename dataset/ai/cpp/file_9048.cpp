#include <algorithm>
#include <vector>
#include <iostream>
int main() {
  std::vector<int> data{2, 4, 6, 21};
  std::cout << std::binary_search(data.begin(), data.end(), 21) << '\n';
}
