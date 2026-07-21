#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int solve(int n, int r)
{
  if (n >= 10) {
    return r;
  } else {
    return r + 100 * (10 - n);
  }
}

int main()
{
  int n, r;
  std::cin >> n >> r;

  std::cout << std::setprecision(20);
  std::cout << solve(n, r) << std::endl;
}
