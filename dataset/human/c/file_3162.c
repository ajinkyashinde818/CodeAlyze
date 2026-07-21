#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int main(){
  int K,N;
  int i,j;
  int max=0;
  
  scanf("%d %d",&K,&N);
  
  int A[N+1];
  int X[N+1];
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<N-1;i++){
    X[i] = A[i+1] - A[i];
  }
  X[i] = K-A[i]+A[0];
  
  for(i=0;i<N;i++){
    if(max < X[i]) max=X[i];
  }
  
  printf("%d\n",K-max);
  
  return 0;
}
