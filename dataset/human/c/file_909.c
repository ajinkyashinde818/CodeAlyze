#include <stdio.h>

int main(void) {
  int i, j, n, sum[100010], a, b, now = 0, ans = 0;
  for(i = 0; i < 100010; ++i) sum[i] = 0;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    sum[a]++;
    sum[b + 1]--;
  }
  /*for(i = 0; i < 10; ++i) printf("%d ", sum[i]);
  printf("\n");*/
  for(i = 1; i < 100010; ++i) {
    now += sum[i];
    if(now + 1 >= i) ans = i - 1;
  }
  if(ans < 0) ans = 0;
  printf("%d\n", ans);
  return 0;
}
