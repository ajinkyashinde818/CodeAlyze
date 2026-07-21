#include<stdio.h>
int main(){

  int i,n,R,max,minR;
  scanf("%d", &n );

  max = -1000000000;
  minR = 1000000000;

  for ( i = 0 ; i < n ; i++ ){

    scanf("%d", &R );

    if ( i > 0 && R - minR > max ) max = R - minR;

    if ( R < minR ) minR = R;
    
  }

  printf("%d\n", max );

  return 0;

}
