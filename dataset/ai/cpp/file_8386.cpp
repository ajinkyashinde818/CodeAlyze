/* Standalone example. */
#include <algorithm>
#include <vector>
#include <iostream>
int main() {
  std::vector<int> data{53, 32, 8};
  std::sort(data.begin(), data.end());
  std::cout << data.front() << '\n';
}
