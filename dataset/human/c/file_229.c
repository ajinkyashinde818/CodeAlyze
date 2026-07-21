#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
  long A[100000],amin,sum;
  int k,i,j,x,y,z,K,N;
  amin=1000000000;
  if(scanf("%d",&N)>1){
    exit(1);
  }
  
  for(i=0;i<N;i++){
  if(scanf("%ld",&A[i])>1){
    exit(1);
  }
  }
  sum = 0;
  k=0;
  for(i=0;i<N;i++){
   if(A[i]<0){
     k=k+1;
   A[i]=labs(A[i]);
   }
   if(amin>A[i]){
   amin = A[i];
   }
   sum = sum + A[i];
  }
  if(k%2!=0){
   sum = sum - 2 * amin;
  }
  printf("%ld",sum);
  return 0;
}
