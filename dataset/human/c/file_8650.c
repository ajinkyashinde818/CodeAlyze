#include <stdio.h>

int main(void) {
   int a;
   scanf("%d", &a);
   int A[a];
   for (int i = 0; i < a; i++ ) {
      scanf("%d", &A[i]);
   }
   int light;
   int count = 1;
   for (light = A[0]; light != 2; count++) {
      if (count >= a ) {
         printf("-1");
         break;
      }
      light = A[light-1];
   }
   if (light == 2 ) {
      printf("%d\n", count);
   }
   return 0;
   



}
