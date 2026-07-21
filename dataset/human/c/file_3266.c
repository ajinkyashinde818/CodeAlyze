#include<stdio.h>
int main(){
  int K,N,i,min;
  scanf("%d%d",&K,&N);
  int A[N+1];
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  min=A[N-1]-A[0];
  for(i=0;i<N-1;i++)
    if(K-A[i+1]+A[i]<min)
      min=K-A[i+1]+A[i];
  printf("%d\n",min);
  return 0;
}
