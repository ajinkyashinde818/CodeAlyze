#include <stdio.h>

int main(void){
   
   int A,B,K;
   
   scanf("%d%d%d",&A,&B,&K);
   
   int i;
   int count = 1;
   int Ans[101];
   
   int min;
   if(A >= B){
      min = B;
   }
   else {
      min = A;
   }
   
   for(i = 1;i <= min;i++){
      if(A%i == 0 && B%i == 0){
         Ans[count] = i;
         count++;
      }
   }
   
   printf("%d\n",Ans[count - K]);
   
   return 0;
}
