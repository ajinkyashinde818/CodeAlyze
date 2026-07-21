#include <stdio.h>

#define N 200000

int main(){
  int n, i, j, maxi, maxj;
  scanf("%d", &n);
  int num[N];
  for(i = 0; i < n; i++) scanf("%d", &num[i]);
  int max = num[1] - num[0];
  maxj = num[1];
  maxi = num[0];
  for(i = 0; i <= n - 2; i++){
    if(num[i] > maxi) continue;
    for(j = i + 1; j <= n - 1; j++){
      int diff = num[j] - num[i];
      if(diff > max) {
        max = diff;
        maxi = num[i];
        maxj = num[j];
      }
    }
  }
  printf("%d\n", max);
  return 0;
}
