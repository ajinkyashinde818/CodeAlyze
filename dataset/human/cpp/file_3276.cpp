#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>

typedef long double ld;
typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

// Split
namespace util {

std::vector< std::string > split(std::string s, char delimiter)
{
  std::vector< std::string > vs;
  std::string sub;
  for (auto c : s) {
    if (c == delimiter) vs.push_back(sub), sub.clear();
    else sub += c;
  }
  vs.push_back(sub);
  return vs;
}

} // namespace util

// Minimum, Maximum
template<class T> T minimum(T head, T tail) { return std::min(head, tail); }
template<class H, class... T> H minimum(H head, T... tail) { return std::min(head, minimum(tail...)); }
template<class T> T maximum(T head, T tail) { return std::max(head, tail); }
template<class H, class... T> H maximum(H head, T... tail) { return std::max(head, maximum(tail...)); }

// Output
template<class T> std::ostream& operator << (std::ostream& os, std::vector< T > v)
{
  for (ll i = 0; i < (ll)v.size(); i++){ os << " [" << i << "]" << v[i]; if (i % 10 == 9) os << std::endl; }
  return os;
}

template<class T, class S> std::ostream& operator << (std::ostream& os, std::vector< std::pair<T, S> > vp)
{
  ll i = 0;
  for (auto p : vp){os << " [" << i++ << "]" << p.first << " " << p.second; if (i % 10 == 0) os << std::endl;}
  return os;
}

void print(){ std::cout << std::endl; }
template<typename H> void print(H head) { std::cout << head << std::endl; }
template<typename H, typename... T> void print(H head, T... tail){ std::cout << head << " ", print(tail...); }

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll N;
  std::cin >> N;
  std::vector< ll > va(N, 0LL);
  for (ll i = 0; i < N; i++) {
    std::cin >> va[i];
  }

  std::vector< std::vector<ll> > dp(N+1, std::vector<ll>(2, 0LL));
  dp[0][0] = 0LL;
  dp[0][1] = -INF;
  for (ll i = 0; i < N; i++) {
    dp[i+1][0] = std::max(dp[i][0] + va[i], dp[i][1] - va[i]);
    dp[i+1][1] = std::max(dp[i][0] - va[i], dp[i][1] + va[i]);
  }

  print(dp[N][0]);
  return 0;
}
