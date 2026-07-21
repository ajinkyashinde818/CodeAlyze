#include <stdio.h>

int main ()
{
   int n, i, s[200000], max, min;

   scanf ("%d", &n);
   for (i = 0; i < n; i++) {
      scanf ("%d", &s[i]);
   }

   min = s[0]; 
   max = s[1] - s[0];
   for (i = 1; i < n; i++) {
      max = (max >= s[i] - min) ? max : s[i] - min;
      min = (min <= s[i]) ? min : s[i];
   }

   printf ("%d\n", max);

   return 0;
}
