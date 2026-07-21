#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
  int N,K;
  scanf("%d%d",&N, &K);

  int *h;

  h = calloc(N, sizeof(int));
  
  int i;
  
  for (i = 1; i <= N; i++) {
    scanf("%d", &h[i]);
  }
  int ans = 0;

  for (i = 1; i <= N; i++) {
    if (h[i] >= K) {
      ans++;
    }
  }
  printf("%d\n", ans);
}
