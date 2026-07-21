#include <stdio.h>
#include <math.h>
#include <stdlib.h>
const int MAX_W = 10000;
const int MAX_H = 10000;
const int MAX_N = 1000;

int main(void) {
  int W, H, N, tx[MAX_N], ty[MAX_N], i;
  scanf("%d %d %d", &W, &H, &N);
  for(i = 0; i < N; ++i) scanf("%d %d", &tx[i], &ty[i]);
  int ny = ty[0], nx = tx[0], ans = 0;
  for(i = 1; i < N; ++i){
    int cnt = 0;
    if(ny < ty[i] && nx < tx[i]){
      cnt = (ty[i] - ny < tx[i] - nx ? ty[i] - ny : tx[i] - nx);
      ans += cnt;
      ny += cnt;
      nx += cnt;
    }else if(ny > ty[i] && nx > tx[i]){
      cnt = (ny - ty[i] < nx - tx[i] ? ny - ty[i] : nx - tx[i]);
      ans += cnt;
      ny -= cnt;
      nx -= cnt;
    }
    ans += abs(ny - ty[i]) + abs(nx - tx[i]);
    ny = ty[i];
    nx = tx[i];
  }
  printf("%d\n", ans);
  return 0;
}
