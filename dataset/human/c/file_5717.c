#include <stdio.h>
 
int main()
{
  int r[200000];
  int n, i, j, max, min;
   
  scanf("%d", &n);
   
  for( i = 0; i < n ; i++ )
  {
    scanf("%d\n", &r[i] );
  }
   
  min = r[0];
  max = r[1] - r[0];
  for (j = 1; j <= n-1 ; j++)
  {
   
    if ( max < r[j] -min )
    {
      max = r[j] - min;
    }
    if ( min > r[j] )
    {
      min = r[j];
    }
     
  }
   printf("%d\n", max);
   
  return 0;
}
