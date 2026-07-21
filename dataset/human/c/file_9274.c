#include <stdio.h>

int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  int h[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &h[i]);
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans += h[i] >= k;
  }
  printf("%d\n", ans);
  return 0;
}
