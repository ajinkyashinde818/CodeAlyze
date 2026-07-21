#include <stdio.h>

main(){
  int N, i, p, min;

  scanf("%d",&N);
  int A[N+1];

  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
    if(i == 1){
      min = A[i-1];
      p = A[i] - A[i-1];
      }
  }
  for(i = 1; i < N; i++){
    if(min > A[i]){
      min = A[i];
    }else if(A[i] - min > p){
      p = A[i] - min;
    }
  }
  printf("%d\n",p);
  return 0;
}
