#include <stdio.h>

int main(void) {
  int N;
  int a[111111];
  int ah[111111] = {0};
  int i, k;
  
  scanf("%d", &N);
  for(i = 0; i < N; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  
  k = 0;
  for(i = 0; i < N; i++) {
    /*printf("%d %d %d\n", k, a[k], ah[k]);*/
    if(ah[k] == 1) {
      printf("-1\n");
      return 0;
    }
    ah[k]++;
    k = a[k];
    if(k == 1) {
      break;
    }
  }
  printf("%d\n", i + 1);
  
  return 0;
}
