#include <stdio.h>
#include <algorithm>
#include <vector>

int main(int argc, char **argv) {
  int N;
  scanf("%d", &N);

  int64_t total = 0;
  std::vector<int64_t> a(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    int tmp;
    scanf("%d", &tmp);
    //tmp = (i <= N / 2) ? 1000000000 : -1000000000;

    total += tmp;
    a[i] = a[i - 1] + tmp;
  }

  int64_t min_diff = 200000000000001;
  for (int i = 1; i <= N - 1; ++i) {
    int64_t diff = std::abs(total - 2 * a[i]);
    min_diff = std::min(diff, min_diff);
  }
  printf("%lld\n", min_diff);

  return 0;
}
