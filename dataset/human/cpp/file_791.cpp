#include <cstdio>

using namespace std;

int main() {
  int a, b, c, n;
  scanf("%d%d%d%d", &a, &b, &c, &n);
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      int k = n - a * i - b * j;
      if (k >= 0 && k % c == 0) {
        ++ans;
      }
    }
  }
  printf("%d\n", ans);
}
