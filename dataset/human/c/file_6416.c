#include<stdio.h>
int main(){
  int i,N;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;++i){
    scanf("%d",&A[i]);
  }
    int min = A[0],max = A[1] - A[0];
    for(i=1;i<N;++i){
      max = max < A[i] - min ? A[i] - min : max;
      min = min > A[i] ? A[i] : min;
    }
    printf("%d\n",max);
    return 0;
  }
