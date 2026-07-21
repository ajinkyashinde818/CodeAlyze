#include <stdio.h>

int main(void)
{
   int i, j, s, n, d, x;
   scanf("%d%d%d", &n, &d, &x);
   int a[n];

   for(i = 0; i < n; i++){
      scanf("%d", &a[i]);
      s = 0;
      for(j = 0; 1; j++){
         if(d / (j*a[i] + 1) > 0){
            s++;
         }
         else{
            break;
         }
      }
      a[i] = s;
   }

   s = 0;
   for(i = 0; i < n; i++){
      s += a[i];
   }
   s += x;

   printf("%d\n", s);

   return 0;
}
