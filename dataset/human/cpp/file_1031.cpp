#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 4000000000000000000LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);
  std::cerr << std::fixed << std::setprecision(6);

  long long R, G, B, N, c = 0;

  std::cin >> R >> G >> B >> N;

  for (int i = 0; i <= 3000; i ++)
    for (int j = 0; j <= 3000; j ++) {
      long long x = N - R * i - G * j;

      if (x >= 0 && x % B == 0)
        c ++;
    }

  std::cout << c << std::endl;

  return 0;
}
