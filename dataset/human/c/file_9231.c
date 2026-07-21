#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
  int N, K, h, result;
  int i;
  scanf ("%d %d", &N, &K);
  
  result = 0;
  for (i=0;i<N;i++) {
      scanf ("%d", &h);
      if (h>=K) result++;
  }
  
  
  printf("%d", result);
  return 0;
}
