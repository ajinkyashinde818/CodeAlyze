#include <stdio.h>

int main(void)
{
  int i, k, n, a[1000000];
  int max = 0;
  
  scanf("%d %d", &k, &n);
  
  for( i = 0; i < n; i++ ){
    scanf("%d", &a[i]);
  }
  
  for( i = 1; i < n; i++ ){
    if( a[i] - a[i-1] > max ){
      max = a[i] - a[i-1];
    }
  }

  if( k + a[0] - a[n-1] > max ){
    max =  k + a[0] - a[n-1];
  }
  
  printf("%d\n", k-max);
}
