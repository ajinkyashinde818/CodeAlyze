#include <cstdio>
#include <cstdint>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<intmax_t> a(N);
  intmax_t sum=0;
  for (size_t i=0; i<N; ++i) {
    scanf("%jd", &a[i]);
    sum += a[i];
  }

  intmax_t x=a[0], y=sum-a[0];
  intmax_t res=std::abs(x-y);
  for (size_t i=1; i+1<N; ++i) {
    x += a[i];
    y -= a[i];
    res = std::min(res, std::abs(x-y));
  }

  printf("%jd\n", res);
}
