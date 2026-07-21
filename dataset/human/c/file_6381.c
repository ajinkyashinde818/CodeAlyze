#include<stdio.h>
#include<stdlib.h>
int main(){
  int *A,i,j,N,minv,maxv=-6000000000,count=0;
  scanf("%d\n",&N);
  A=(int *)malloc(N*sizeof(int));
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  minv=A[0];
  for(j=1;j<=N-1;j++){
    if(maxv<A[j]-minv) maxv=A[j]-minv;
    if(minv>A[j]) minv=A[j];
  }
  printf("%d\n",maxv);
  return 0;
}
