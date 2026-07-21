#include <stdio.h>

int main( int argc , char *argv[] )
{
  int R,G,B,N;
  int cnt = 0;
  int r,g;
  
  scanf( "%d %d %d %d\n" , &R , &G , &B , &N );
  
  for( r = 0 ; r < ( N / R ) + 1 ; r++ ) {
    for( g = 0 ; g < ( N / G ) + 1 ; g++ ) {
      int tmp = N - r*R - g*G;
      
      if( tmp % B == 0 && tmp >= 0 ) {
        cnt++;
      }
    }
  }
  
  printf( "%d\n" , cnt );
  
  return 0;
}
