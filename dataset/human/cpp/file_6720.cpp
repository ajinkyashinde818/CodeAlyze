#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

intmax_t gcd(intmax_t m, intmax_t n) {
  while (n) std::swap(m %= n, n);
  return m;
}

intmax_t tenpow(intmax_t k) {
  intmax_t res = 1;
  for (int i = 0; i < k; ++i) res *= 10;
  return res;
}

int main() {
  intmax_t a;
  scanf("%jd.", &a);

  char buf[16] = "";
  scanf("%[^(\n]", buf);
  std::string f0 = buf;
  std::string f1 = "";
  if (scanf("(%[^)\n])", buf) == 1) f1 = buf;

  intmax_t m = f0.length();
  intmax_t n = f1.length();

  intmax_t b = std::stoi("0"+f0);
  intmax_t c = std::stoi("0"+f1);

  if (n == 0) {
    intmax_t q = a * tenpow(m);
    q += b;
    intmax_t d = tenpow(m);

    intmax_t g = gcd(q, d);
    q /= g;
    d /= g;
    printf("%jd/%jd\n", q, d);
    return 0;
  }

  intmax_t q = a * tenpow(m) * (tenpow(n)-1);
  q += b * (tenpow(n)-1);
  q += c;

  intmax_t d = tenpow(m) * (tenpow(n)-1);
  intmax_t g = gcd(q, d);
  q /= g;
  d /= g;
  printf("%jd/%jd\n", q, d);
}
