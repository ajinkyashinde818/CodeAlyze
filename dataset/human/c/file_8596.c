#include <stdio.h>

int main()
{
     int n, i;
     scanf("%d", &n);

     int a[n+1], b[n+1];
     for(i = 0; i < n; i++){
          scanf("%d", &a[i]);
          b[i] = -0;
     }

     int count = 1;
     int nx = a[0];
     b[nx - 1]++;

     while(nx != 2)
     {
          nx = a[nx - 1];
          b[nx - 1]++;
          if(b[nx - 1] > 1)
          {
               printf("-1\n");
               return 0 ;
          }
          count++;
     } 
     printf("%d\n", count);
     return 0;
}
