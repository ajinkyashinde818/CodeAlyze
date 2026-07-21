#include <stdio.h>

int main(void) {
   
   int N,M;
   
   scanf("%d%d",&N,&M);
   
   int *A = malloc(sizeof(int)*(M+1));
   
   int i;
   int *Check = malloc(sizeof(int)*(N+1));
   
   
   for (i = 1; i <= N; i++) {
      Check[i] = 0;
   }
   
   for (i = 1; i <= M; i++) {
      scanf("%d",&A[i]);
      Check[A[i]] = 1;
   }
  
   int *Ans = malloc(sizeof(int)*(N+1));
   
   if (Check[1] == 1) {
      Ans[1] = 0;
   }
   else {
      Ans[1] = 1;
   }
   
   if (Check[2] == 1) {
      Ans[2] = 0;
   }
   else {
      Ans[2] = Ans[1] + 1;
   }
   
   for (i = 3; i <= N; i++) {
      if (Check[i] == 1) {
         Ans[i] = 0;
      }
      else {
         Ans[i] = (Ans[i - 1] + Ans[i - 2])%1000000007;
      }
      
   }
   
   /*
   for (i = 1; i <= N; i++) {
      printf("%d-->%d\n",i,Ans[i]);
   }
    */
   
   printf("%d\n",Ans[N]);
   
   
   return 0;
}
