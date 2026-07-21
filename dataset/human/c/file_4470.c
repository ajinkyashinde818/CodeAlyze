#include <stdio.h>
#include <string.h>
int main()
{
   int n, i, count = 0;
   scanf("%d", &n);
   int a[n], b[n];
   for (i = 0; i < n; i++)
      scanf("%d%d", &a[i], &b[i]);

   for (i = 0; i < n; i++)
   {
      if (a[i] == b[i])
         count++;
      else
         count = 0;
      if (count == 3)
      {
         printf("Yes");
         return 0;
      }
   }
   printf("No");
}
