#include <stdio.h>
int main(void){
   int N,A[20],B[20],C[20],i,S=0;
   scanf("%d",&N);
   for(i=0;i<N;i++){
       scanf("%d",&A[i]);
   }
    for(i=0;i<N;i++){
       scanf("%d",&B[i]);
       S+=B[i];
   }
   
   for(i=1;i<N;i++){
       scanf("%d",&C[i]);
   }
   
   for(i=0;i<N-1;i++){
       if(A[i]+1==A[i+1])
       S+=C[A[i]];
   }
   printf("%d",S);
   return(0); 
}
