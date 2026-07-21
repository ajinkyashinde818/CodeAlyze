#include<stdio.h>
int main()
{
  int  x, n, sa, ans;
  int min = 200000, i = 0;
  scanf("%d", &n);
  scanf("%d", &x);
  min = x;
  ans = -10000000000;
  for ( i = 1 ; i < n ; i++ ){
  	
    scanf("%d", &x);
    
      sa = x - min;
      if (min > x){
        min = x;
      }
      
      if (ans < sa ){
        ans = sa;
      }
  }
  printf("%d\n", ans);
  
  return 0;
}
