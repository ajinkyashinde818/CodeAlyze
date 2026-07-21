#include <iostream>
#include <vector>
#include <queue>
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
#include <bitset>

constexpr long long MOD = 1000000007;

int main()
{
  int R, G, B, N;
  std::cin >> R >> G >> B >> N;
  int ans = 0;
  int r = N / R;
  for (int i = 0; i <= r; ++i)
  {
    int n = N - R * i;
    int g = n / G;
    for (int j = 0; j <= g; ++j)
    {
      int n1 = n - G * j;
      if (n1 % B == 0)
        ++ans;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
