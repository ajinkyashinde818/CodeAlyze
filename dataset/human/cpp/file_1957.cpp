#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <limits>
#include <algorithm>
#include <memory>
#include <climits>

constexpr long long MOD = 1000000007;

int gcd(int m, int n)
{
  return n == 0 ? m : gcd(n, m % n);
}

int main()
{
  int N;
  std::cin >> N;
  std::vector<long long> a(N);
  for (auto& val: a)
    std::cin >> val;
  std::vector<long long> dp1(N, 0);
  std::vector<long long> dp2(N, 0);
  dp1[1] = a[0] + a[1];
  dp2[1] = -a[0] -a[1];
  for (int i = 2; i < N; ++i)
  {
    dp1[i] = std::max(dp1[i-1]+a[i], dp2[i-1]+a[i]);
    dp2[i] = std::max(dp1[i-1]-a[i]-2*a[i-1], dp2[i-1]-a[i]+2*a[i-1]);
  }
  std::cout << std::max(dp1.back(), dp2.back()) << std::endl;
  return 0;
}
