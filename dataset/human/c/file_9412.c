#include<stdio.h>
#include<stdlib.h>

int main(void){
     
     int i,j;
     int N,D,X;
     int A[100];
     int sum;

     scanf("%d",&N);
     scanf("%d %d",&D, &X);
     for(i=0;i<N;i++){
         scanf("%d",&A[i]);
     }

     sum = X;
     for(i=0;i<N;i++){
         sum += (D-1) / A[i] +1;
     }

     printf("%d\n",sum);

  
}
