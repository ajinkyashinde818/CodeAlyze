#include <stdio.h>
int main()
{
  int n ;
  scanf("%d", &n) ;

  int r0, r1 ;
  scanf("%d %d",&r0,&r1) ;

  int maxv = r1-r0 ;
  int minv ;
  if( r1 <= r0 ){
    minv = r1 ;
  }else{
    minv = r0 ;
  }

  int r, i ;
  for( i = 0 ; i < n - 2 ; i++ ){
    scanf("%d", &r) ;
    if( maxv <= r - minv ){
      maxv = r - minv ;
    }
    if( minv >= r ){
      minv = r ;
    }
  }
  printf("%d\n", maxv) ;
  
  return 0 ;
}
