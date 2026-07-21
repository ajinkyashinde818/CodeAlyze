#include <stdio.h>

int main(void) {
  int i, j, ans = 0, k, s;
  scanf("%d%d", &k, &s);
  for(i = 0; i <= k; ++i) for(j = 0; j <= k; ++j) if(s - i - j <= k && i + j <= s) ++ans;
  printf("%d", ans);
  return 0;
}
