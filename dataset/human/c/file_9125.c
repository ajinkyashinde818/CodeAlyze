#include <stdio.h>

int main (void){
   int N,K;
   scanf("%d %d",&N,&K);
   int high[N];
   int i;
   int count=0;
   for(i=0;i<N;i++){
       scanf("%d",&high[i]);
       if(high[i]>=K){
           count++;
       }
   }
   printf("%d",count);
   return 0;
}
