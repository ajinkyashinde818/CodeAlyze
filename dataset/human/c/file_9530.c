#include <stdio.h>

int main(void){
  int N, D, X;
  int A[100];
  
  scanf("%d%d%d", &N, &D, &X);
  int i;
  for(i=0;i<N;i++)	scanf("%d", &A[i]);
  
  int ans = 0;
  for(i=0;i<N;i++){
    int j=0;
    while( j*A[i]+1 <= D ){
      ans++;
      j++;
    }
  }
  
  printf("%d\n", ans + X );
  
  return 0;
}
