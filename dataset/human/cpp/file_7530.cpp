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
  std::vector< ll > vsum(N, 0LL);

  std::cin >> va[0];
  vsum[0] = va[0];
  for (ll i = 1; i < N; i++) {
    std::cin >> va[i];
    vsum[i] = vsum[i-1] + va[i];
  }

  ll ans = INF;
  for (ll i = 0; i < N-1; i++) {
    ll x = vsum[i];
    ll y = vsum[N-1] - vsum[i];
    ll calc = std::abs(x - y);
    ans = std::min(ans, calc);
  }

  print(ans);
  return 0;
}
