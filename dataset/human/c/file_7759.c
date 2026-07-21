#include <stdio.h>
 int main(void){
   int times,i;

   scanf("%d",&times);

   int K[times];
   int P[times];

   for(i=0;i<times;i++){
     scanf("%d %d",&K[i],&P[i]);
   }

   for(i=0;i<times;i++){
     if(K[i]%P[i]==0){
       printf("%d\n",P[i]);
     }else{
       printf("%d\n",K[i]%P[i]);
     }
   }
   return 0;
 }
