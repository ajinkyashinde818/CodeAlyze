#include<stdio.h>
int main(){
  int K,N,i,max,dis;
  int A[200000];
  max=0;
  scanf("%d%d",&K,&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=1;i<N;i++){
    dis=A[i]-A[i-1];
    if(dis>max)
      max=dis;
  }
  
  dis=A[0]+K-A[N-1];
  if(dis>max)
    max=dis;
  
  dis=K-max;
  
  printf("%d",dis);
  
  return 0;
}
