#include<stdio.h>

int main(){

  int i,j,k;
  int N,D,X;
  int s=0;
  
  scanf("%d",&N);
  scanf("%d %d",&D,&X);
  int A[N];
  int B[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
	B[i]=A[i];
  }   
  
  s += N;
  
  for(i=2;i<=D;i++){
    for(j=0;j<N;j++){
      if((i) == A[j]+1){
        s++;
        A[j]+=B[j];
      }
    }
  }
  
  printf("%d\n",s+X);
  return 0;
}
