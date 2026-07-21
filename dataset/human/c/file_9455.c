#include<stdio.h>
 int main(void)
 {
     int N,D,X,A[105];
     int i,j,k=0;

     scanf("%d",&N); // menber
     scanf("%d%d",&D,&X); // days rest

     for(i=0;i<N;i++)
       scanf("%d",&A[i]); // number

     for(i=0;i<N;i++){
       for(j=1;j<100;j++){
         if(j*A[i]+1<=D) k++;
         else break;
       }
     }

     printf("%d\n",k+N+X);

     return 0;
 }
