#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
int main() {
  int n;
  std::cin >> n;
  std::vector<int> a;
  a.resize(n);
  for (auto &ai: a) std::cin >> ai;
  int num_negatives = 0;
  for (auto ai: a) if (ai < 0) num_negatives++;
  for (auto &ai: a) ai = std::abs(ai);
  if (num_negatives % 2 == 1) {
    auto i =  std::min_element(a.begin(), a.end());
    *i = -*i;
  }
  std::cout << std::accumulate(a.begin(), a.end(), 0LL);
}
