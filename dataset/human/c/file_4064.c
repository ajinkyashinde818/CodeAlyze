#include<stdio.h>
 int main(void)
 {
     int A,B,K,i,j=0,C[100];

     scanf("%d%d%d",&A,&B,&K);

     for(i=1;i<=100;i++){
       if((A%i==0)&&(B%i==0)){
          C[j]=i; j++;
       }
     }
     printf("%d\n",C[j-K]);

     return 0;
 }
