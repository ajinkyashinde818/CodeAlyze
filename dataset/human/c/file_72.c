#include <stdio.h>

int main(){
  int R, G, B, N, ans = 0;
  scanf("%d %d %d %d", &R, &G, &B, &N);
  for(int i = 0; i <= 3000; i++){
    for(int j = 0; j <= 3000; j++){
      int v = R * i + G * j;
      if(N >= v && (N - v) % B == 0) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
