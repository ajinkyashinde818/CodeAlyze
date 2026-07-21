#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
// constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

namespace detail {
template <typename Tp, size_t N>
std::vector<Tp> make_vector(
    std::vector<size_t>& sizes,
    typename std::enable_if<(N == 1), Tp const&>::type x
) {
  return std::vector<Tp>(sizes[0], x);
}
template <typename Tp, size_t N>
auto make_vector(
    std::vector<size_t>& sizes,
    typename std::enable_if<(N > 1), Tp const&>::type x
) {
  size_t size = sizes[N-1];
  sizes.pop_back();
  return std::vector<decltype(make_vector<Tp, N-1>(sizes, x))>(
      size, make_vector<Tp, N-1>(sizes, x)
  );
}
}  // detail::

template <typename Tp, size_t N>
auto make_vector(size_t const(&sizes)[N], Tp const& x = Tp()) {
  std::vector<size_t> s(N);
  for (size_t i = 0; i < N; ++i) s[i] = sizes[N-i-1];
  return detail::make_vector<Tp, N>(s, x);
}

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<intmax_t> a(n);
  for (auto& ai: a) scanf("%jd", &ai);

  intmax_t inf = 1e18;
  auto dp = make_vector<intmax_t>({n+1, 2_zu}, -inf);
  dp[0][0] = 0_jd;

  for (size_t i = 0; i < n; ++i) {
    dp[i+1][0] = std::max({dp[i+1][0], dp[i][0]+a[i], dp[i][1]-a[i]});
    dp[i+1][1] = std::max({dp[i+1][1], dp[i][0]-a[i], dp[i][1]+a[i]});
  }

  printf("%jd\n", dp[n][0]);
}
