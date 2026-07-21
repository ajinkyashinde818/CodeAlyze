#include <stdio.h>

int main() {
  int r, g, b, n;
  scanf("%d %d %d %d", &r, &g, &b, &n);
  long long ans = 0;
  for (int i = 0; i <= 3000; i++) {
    for (int j = 0; j <= 3000; j++) {
      int rpg = i * r + g * j;
      if (rpg <= n) {
        if ((n - rpg) % b == 0) {
          ans++;
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
