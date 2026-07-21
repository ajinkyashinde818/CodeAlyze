#include <cstdio>
#include <cstdint>
#include <string>

int main() {
  int Q;
  scanf("%d", &Q);

  uintmax_t sign = 0x80000000uLL;

  for (int i = 0; i < Q; ++i) {
    uintmax_t n;
    scanf("%jx", &n);

    bool neg = false;
    if (n & sign) {
      n ^= sign;
      neg = true;
    }
    intmax_t ipart = n >> 7;
    intmax_t fpart = n & 127;

    if (neg) printf("-");
    if (fpart == 0) {
      printf("%jd.0\n", ipart);
    } else {
      char buf[1024];
      snprintf(buf, sizeof buf, "%.12f", n/128.0);
      std::string res(buf);
      while (res.back() == '0') res.pop_back();
      printf("%s\n", res.c_str());
    }
  }
}
