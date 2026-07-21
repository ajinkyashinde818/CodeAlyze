#include <stdio.h>

int main (void) {

   int N;
   
   scanf("%d",&N);

   int A[N];
   
   int minus_num = 0;
   int abs_min = pow(10,9) + 1;
   long sum = 0;
   int i;
   for (i = 0; i < N; i++) {
      scanf("%d",&A[i]);
      if(A[i] < 0) {
         minus_num++;
      }
      if (abs_min > abs(A[i])) {
         abs_min = abs(A[i]);
      }
      sum = sum + abs(A[i]);
   }

   if (minus_num%2 == 0) {
      printf("%ld\n",sum);
   }
   else {
      printf("%ld\n",sum - 2*abs_min);
   }
   
   return 0;
   
}
