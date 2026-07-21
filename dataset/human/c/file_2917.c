#include <stdio.h>

int main(void) {
  int K, S;
  int X, Y, Z;
  int ans = 0;
  
  scanf("%d %d", &K, &S);
  for(X = 0; X <= K; X++) {
    for(Y = 0; Y <= K; Y++) {
      Z = S - X - Y;
      if(0 <= Z && Z <= K) ans++;
    }
  }
  printf("%d\n", ans);
  
  return 0;
}
