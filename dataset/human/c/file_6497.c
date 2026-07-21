#include <stdio.h>
#include <limits.h>

int main(){
  int n, min = 0, max = INT_MIN;
  scanf("%d\n", &n );

  for( int i = 0; i < n; i ++ ){
    int k;
    scanf("%d\n", &k );
    if( min == 0 ){
      min = k;
      continue;
    }
    if( k - min > max ) max = k - min;
    if( k < min ) min = k;
  }
  printf("%d\n", max );
  return 0;
}
