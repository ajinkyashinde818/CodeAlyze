#include <stdio.h>
#define max(a, b) a>b ? a : b

int main(){
  int k, n, i, zeroA, prevA, nowA, ans, Max=0;
  scanf("%d%d", &k, &n);
  scanf("%d", &zeroA);
  prevA = zeroA;
  for(i=1; i<n; i++){
    scanf("%d", &nowA);
    Max = max(Max, nowA-prevA);
    prevA = nowA;
  }
  Max = max(Max, zeroA+(k-nowA));
  ans = k-Max;
  printf("%d\n", ans);
  return 0;
}
