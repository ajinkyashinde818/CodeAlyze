#include <stdio.h>

int main(){
  int n, k, i, c;
  
  scanf("%d %d", &n, &k);
  int A[n];
  for (i=0; i<n; i++) scanf("%d", &A[i]);
  for (i=0; i<n; i++){
    if (A[i] >= k) {
      c = c+1;
    }
    
  }
  printf("%d", c);
  return 0;
}
