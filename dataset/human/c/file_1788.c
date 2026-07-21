#include <stdio.h>

int main(void){

  int N;
  scanf("%d",&N);
  int i, A[N], B[N], C[N-1];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }  for(i=0;i<N;i++){
    scanf("%d",&B[i]);
  }  for(i=0;i<N-1;i++){
    scanf("%d",&C[i]);
  }
  int j, count=0;
  for(j=0;j<N;j++){
    count+=B[A[j]-1];
    if(j>0&&A[j-1]+1==A[j]){
      count+=C[A[j-1]-1];
    }

  }
   
  printf("%d",count);
  return 0;
}
