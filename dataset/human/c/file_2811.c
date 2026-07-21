#include <stdio.h>

int main(void)
{
  int i, j, k, s, count = 0;
  
  scanf("%d %d", &k, &s);
  
    for( i = 0; i <= k; i++ ){
      for( j = 0; j <= k; j++ ){
        if( s-k <= i+j && i+j <= s ){
          count += 1;
        }
      }
    }
  
  printf("%d\n", count);
  
  return 0;
}
