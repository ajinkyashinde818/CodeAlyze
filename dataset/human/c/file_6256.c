#include <stdio.h>

int main(void){
   int n, i, j, m, x, y;

   scanf("%d", &n);

   int a[n];

   for(i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }

   x = a[1] - a[0];
   y = a[0];

   for(j = 1; j < n; j++) {
      if (a[j - 1] < y){
         y = a[j - 1];
      }
      if (a[j] >= y){
         m = a[j] - y;
         if (x < m){
            x = m;
         }
      }
   }

   printf("%d\n", x);

   return 0;
}
