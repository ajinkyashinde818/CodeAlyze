#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

intmax_t f(std::vector<std::pair<intmax_t, intmax_t>> const& xv, intmax_t c) {
  size_t n = xv.size();
  intmax_t res = 0;
  std::vector<intmax_t> lf(n+1), rg(n+1);
  {
    intmax_t acc = 0;
    for (size_t i = 0; i < n; ++i) {
      acc += xv[i].second;
      lf[i+1] = std::max(lf[i], acc - 2*xv[i].first);
      res = std::max(res, acc-xv[i].first);
    }
  }
  {
    intmax_t acc = 0;
    for (size_t i = n; i--;) {
      acc += xv[i].second;
      rg[i] = std::max(rg[i+1], acc - (c-xv[i].first));
    }
  }
  for (size_t i = 0; i <= n; ++i)
    res = std::max(res, lf[i]+rg[i]);

  return res;
}

int main() {
  size_t n;
  intmax_t c;
  scanf("%zu %jd", &n, &c);

  std::vector<std::pair<intmax_t, intmax_t>> xv(n);
  for (auto& p: xv)
    scanf("%jd %jd", &p.first, &p.second);

  intmax_t res = f(xv, c);
  std::reverse(xv.begin(), xv.end());
  for (auto& p: xv) p.first = c - p.first;
  res = std::max(res, f(xv, c));
  printf("%jd\n", res);
}
