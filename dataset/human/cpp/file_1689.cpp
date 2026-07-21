#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <string>

int main() {
  size_t N;
  scanf("%zu", &N);

  if (N == 1) return puts("Yes\n2\n1 1\n1 1"), 0;
  if (N == 2) return puts("No"), 0;
  if (N == 3) return puts("Yes\n3\n2 1 2\n2 3 1\n2 2 3"), 0;
  if (N == 4) return puts("No"), 0;

  for (size_t i=1; i<1000; ++i) {
    size_t w=i*(i+1)/2;
    if (w > N) return puts("No"), 0;
    if (w < N) continue;

    size_t k=i+1;
    std::vector<std::vector<size_t>> res(k);
    size_t a=1;
    for (size_t j=0; j<i; ++j) {
      for (size_t m=0; m<=j; ++m) {
        // size_t a=j*(j+1)/2+1+m;
        res[m].push_back(a);
        res[j+1].push_back(a);
        ++a;
      }
    }
    puts("Yes");
    printf("%zu\n", k);
    for (size_t i=0; i<k; ++i) {
      printf("%zu", res[i].size());
      for (size_t a: res[i])
        printf(" %zu", a);
      printf("\n");
    }
    return 0;
  }
}
