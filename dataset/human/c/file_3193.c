#include <stdio.h>
int main(){
  int K,N,i,j,tmp,ans,max,d;
  int A[1000000];
  scanf("%d %d",&K,&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  
  max=A[0]+K-A[N-1];
  for(i=0;i<N;i++){
    d=A[i+1]-A[i];
    if(d>max) max=d;
  }
  
  ans=K-max;
  printf("%d",ans);
  return 0;
}
