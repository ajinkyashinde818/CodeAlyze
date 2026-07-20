#include <algorithm>
#include <vector>
#include <iostream>
int main() {
  std::vector<int> data{71, 27, 9};
  std::sort(data.begin(), data.end());
  std::cout << data.front() << '\n';
}
