#include <stdio.h>

int main(void) {
   
   int R,G,B,N;
   
   scanf("%d%d%d%d",&R,&G,&B,&N);
   
   int i,j;
   int ans = 0;
   
   for (i = 0; i <= N; i++) {
      for (j = 0; j <= N; j++) {
         if ((i*R + j*G) <= N && (N - (i*R + j*G))%B == 0) {
            //printf("%d %d %d\n",i,j,(N - (i*R + j*G))/B);
            ans++;
         }
         if (j*G > N) {
            break;
         }
      }
   }
   
   printf("%d\n",ans);
   
   return 0;
   
}
