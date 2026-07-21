#include <stdio.h>

int main(void)
{
  int n, k;
  scanf("%d%d", &n, &k);
  int h[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(h[i] >= k) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
