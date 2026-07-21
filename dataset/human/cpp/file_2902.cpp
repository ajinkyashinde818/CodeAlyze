#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
const int INF = 1e9;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

int main()
{
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
  }
  vector<vector<ll>> dp(N + 1, vector<ll>(2, 0));
  dp[0][1] = -1e15;
  for (int i = 0; i < N; ++i)
  {
    dp[i + 1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i]);
    dp[i + 1][1] = max(dp[i][0] - A[i], dp[i][1] + A[i]);
  }
  cout << dp[N][0] << endl;

  return 0;
}
