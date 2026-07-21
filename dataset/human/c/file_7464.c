#include <stdio.h>

int main(void)
{
  int x[10000];
  int n = 0;
  int i;
  
  do{
    
    scanf("%d", x+n);
    n++;
  }while(*(x+n-1));
  
  for( i = 0; i < n-1; i++ ){
    printf("Case %d: %d\n", i+1, x[i]); 
  }

  return 0;
  
}
