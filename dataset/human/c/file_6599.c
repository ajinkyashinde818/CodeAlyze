#include <stdio.h>
#define NUMBER 200000
int main () {
   int n, i, j, a, x[NUMBER];
   long minv, maxv;

   scanf("%d\n", &n);

   for (i = 0; i < n; i++) {
     scanf("%d\n", &x[i]);
   }

   minv = x[0];
   maxv = x[1] - x[0];

   for (j = 1; j < n; j++) {
     a = x[j] - minv;

     if (maxv < a) {
       maxv = a;
     }

     if (minv > x[j]) {
       minv = x[j];
     }

   }

   printf("%d\n", maxv);

   return 0;

}
