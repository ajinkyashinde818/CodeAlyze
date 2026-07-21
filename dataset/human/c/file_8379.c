#include <stdio.h>

int main(void) {
   
   int N,K;
   
   scanf("%d",&N);
   
   char Moji[N+10];
   
   scanf("%s",Moji);
   scanf("%d",&K);
   
   int i;
   
   for(i = 0;i < N;i++){
      if(Moji[i] != Moji[K-1]) {
         Moji[i] = '*';
      }
   }
   
   printf("%s\n",Moji);
   
   return 0;
}
