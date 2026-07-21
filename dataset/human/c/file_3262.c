#include <stdio.h>

int main(){
  int K,N,A[200002],M;
  scanf("%d %d",&K,&N);
  for(int i=1;i<=N;i++){
    scanf("%d",A+i);
  }
  M=K-(A[N]-A[1]);
  for(int i=1;i<N;i++){
    if(M<A[i+1]-A[i]) M=A[i+1]-A[i];
  }
  printf("%d\n",K-M);
  return 0;
}
