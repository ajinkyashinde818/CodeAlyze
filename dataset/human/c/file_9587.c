#include<stdio.h>
int main(void){
  int N,D,X,i,j,C;
  scanf("%d",&N);
  scanf("%d %d",&D,&X);
  int A[N+1];
  for(i=1;i<=N;i++){
    scanf("%d",&A[i]);
    for(j=0;j*A[i]+1<=D;j++){
    }
    A[i] = j;
    C = C + A[i];
  }
  C = C + X;
  printf("%d",C);
  return 0;
}
