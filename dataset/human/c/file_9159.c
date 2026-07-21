#include <stdio.h>
#include <math.h>
 
int main(){
  int N, K;
  scanf("%d %d", &N, &K);
  int h[N], i, ans = 0;
  for(i=0; i<N; i++){
    scanf("%d", &h[i]);
    if (h[i] >= K) ans++;
  }

  printf("%d", ans);

  return 0;
}
