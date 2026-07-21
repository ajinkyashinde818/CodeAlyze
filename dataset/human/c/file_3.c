#include <stdio.h>

int GetNum(int n, int a, int b) {
  int ans = 0;
  for (int i = 0; i <= n; i += a) {
    if ((n - i) % b == 0) { ans++; }
  }
  return ans;
}

int main() {
  int r, g, b, n;
  scanf("%d%d%d%d", &r, &g, &b, &n);
  int ans = 0;
  for (int num = 0; num <= n; num += r) {
    ans += GetNum(n - num, g, b);
  }
  printf("%d\n", ans);
  return 0;
}
