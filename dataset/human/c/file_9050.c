#include <stdio.h>

int main(void) {
  int i, n, k, ans, height;
  
  ans = 0;
  
  scanf("%d", &n);
  scanf("%d", &k);
  
  for(i=0;i<n;i++) {
    scanf("%d", &height);
    if(height >= k) ans++;
  }
  
  printf("%d", ans);

  return 0;
}
