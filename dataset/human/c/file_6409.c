#include <stdio.h>

#define N 200000

int main()
{
  int n;   //integer 
  int t[N];   //price
  int i, j;   //loop counter variable
  int max=-2000000000, min;   //maximum variable

  scanf("%d", &n);

  for( i = 0 ; i < n ; i++ ) scanf("%d", &t[i]);
 
  min = t[0];

  for( i = 1 ; i < n ; i++ ){
    if( max < (t[i] - min) ) max = t[i] - min;
    if( min > t[i] ) min = t[i];
  }

  printf("%d\n", max);

  return 0;
}
