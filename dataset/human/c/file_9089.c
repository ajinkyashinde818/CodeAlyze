#include <stdio.h>

int main(void){
  int n,k,i;
  int ans = 0;
  scanf("%d%d", &n, &k);
  int L[n];
  for (i = 0; i < n; i++){
    scanf("%d", &L[i]);
  }
  for (i = 0; i < n; i++){
    if (L[i] >= k){
      ans++;
    }
  }
  printf("%d", ans);
  return 0;
}
