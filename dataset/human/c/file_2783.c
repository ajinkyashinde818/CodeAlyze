#include <stdio.h>

int main (void) {
  int K, S;
  int i, j, k;
  int cnt = 0;
  
  scanf("%d %d", &K, &S); 
  
  for (i=0; i <= K; i++) {
    for (j=0; j<=K; j++) {
      k = S-i-j;
        if (k<= K && k>=0) cnt++;
    }
  }
  
  printf("%d\n", cnt);
  
  return 0;
}
