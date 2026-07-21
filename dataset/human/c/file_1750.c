#include <stdio.h>

int main(void)
{
  int N,A[20],B[50],C[50],i,s;

  scanf("%d",&N);

  for(i=0;i<N;i++){
   scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
   scanf("%d",&B[i]);
  }
   for(i=0;i<N-1;i++){
   scanf("%d",&C[i]);
  }

   s=0;
   for(i=0;i<N;i++){
    s+=B[A[i]-1];
    if((i>0)&&(A[i]==A[i-1]+1)){
     s+=C[A[i-1]-1];  
    }
   }

   printf("%d\n",s);

  return 0;
 }
