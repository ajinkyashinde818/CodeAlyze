#include <stdio.h>
void main(void)
{      
     int K,N,max,i;
 scanf("%d %d",&K,&N);
  
  int A[N+1];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  A[N]=A[0]+K;



     max=A[1]-A[0];
  for(i=0;i<N-1;i++){
   if(max<(A[i+2]-A[i+1]))
     max=A[i+2]-A[i+1];
  }


  
  printf("%d",K-max);
}
