#include<stdio.h>
#include<stdlib.h>

int main(){
 int N,K,S,i;
  scanf("%d %d %d",&N,&K,&S);
  int *A=(int*)malloc(sizeof(int)*N);
  for(i=0;i<K;i++)A[i]=S;
  if(S==1000000000)S=0;
  for(i=K;i<N;i++)A[i]=S+1;
  for(i=0;i<N;i++)printf("%d ",A[i]);
  free(A);
  return 0;
}
