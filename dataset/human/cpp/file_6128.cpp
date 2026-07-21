#include <algorithm>
#include <array>
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


int N, v[111111];

long long C, x[111111];


long long compute()
{
  long long G[111111], H, I, Gp = -INF, X, V = 0, r = -INF;

  for (int i = 0; i <= N; i ++) {
    X  = x[i];
    V += v[i];

    G[i] = Gp = std::max(V - X, Gp);
  }

  r = Gp;

  V = 0;
  
  Gp = -INF;

  for (int i = N; i > 0; i --) {
    X  = C - x[i];
    V += v[i];

    H = V - X;
    I = V - X - X + G[i - 1];

    Gp = std::max({H, I, Gp});
  }

  return std::max(Gp, r);
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);
  std::cerr << std::fixed << std::setprecision(6);

  std::cin >> N >> C;

  x[0] = v[0] = 0;

  for (int i = 1; i <= N; i ++)
    std::cin >> x[i] >> v[i];

  long long r = -INF;

  r = std::max(compute(), r);

  std::reverse(x + 1, x + N + 1);
  std::reverse(v + 1, v + N + 1);

  for (int i = 1; i <= N; i ++)
    x[i] = C - x[i];

  r = std::max(compute(), r);

  std::cout << r << std::endl;

  return 0;
}
