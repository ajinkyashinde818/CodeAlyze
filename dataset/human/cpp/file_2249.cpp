#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using Value = std::int64_t;

Value solve(std::vector<Value> array)
{
  int count_of_negative = 0;
  for (auto& v : array) {
    if (v < 0) {
      ++count_of_negative;
      v = -v;
    }
  }
  auto result = std::accumulate(array.begin(), array.end(), Value{0});
  if (count_of_negative % 2) {
    result -= 2 * *std::min_element(array.begin(), array.end());
  }
  return result;
}

int main()
{
  int n;
  std::cin >> n;

  std::vector<Value> longs(n);
  for (auto& a : longs) {
    std::cin >> a;
  }

  std::cout << solve(longs) << std::endl;
}
