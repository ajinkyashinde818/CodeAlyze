#include <stdio.h>

int main(void) {
   
   int K,N;
   
   scanf("%d%d", &K, &N);
   
   int i;
   int A[N];
   
   for (i = 0; i < N; i++) {
      scanf("%d", &A[i]);
   }
   
   int Distance[N];
   
   for (i = 0; i < N - 1; i++) {
      Distance[i] = A[i+1] - A[i];
   }
   Distance[N-1] = K - A[N-1] + A[0];
   
   int max_distance = 0;
   
   for (i = 0; i < N; i++) {
      if (max_distance <= Distance[i]) {
         max_distance = Distance[i];
      }
   }
 
   printf("%d\n", K - max_distance);
   
   
   return 0;
}
