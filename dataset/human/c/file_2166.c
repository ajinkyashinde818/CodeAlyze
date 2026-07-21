#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char str[100010];
char str1[200010];
char str2[200010];


int main( int argc, char *argv[] )
{
  int q = 0;
  int f=0;
  int t;
  int ff;
  char c;
  int s1 =0 ;
  int s2 =0 ;
  int i;
  
  scanf( "%s", str );
  scanf( "%d", &q );
  for( i = 0 ; i < q ; i ++ ){
    scanf( "%d", &t );
    if( t == 1 ){
      if( f ) f = 0;
      else f = 1;
    }
    else{
      scanf( "%d %c", &ff, &c );
      if( (f==0 && ff==1) || (f==1 && ff==2) ){
	str1[s1++] = c;
      }
      else{
	str2[s2++] = c;
      }
    }
  }

//printf( "%d %s %s %s\n", f, str1, str, str2 );

  if( f == 0 ){
    int sss;
    for( i = 0 ; i < s1 ; i ++ ){
      printf( "%c", str1[s1-i-1] );
    }
    sss = strlen( str );
    for( i = 0 ; i < sss ; i ++ ){
      printf( "%c", str[i] );
    }
    for( i = 0 ; i < s2 ; i ++ ){
      printf( "%c", str2[i] );
    }
  }
  else{
    int sss;
    for( i = 0 ; i < s2 ; i ++ ){
      printf( "%c", str2[s2-i-1] );
    }
    sss = strlen( str );
    for( i = 0 ; i < sss ; i ++ ){
      printf( "%c", str[sss-i-1] );
    }
    for( i = 0 ; i < s1 ; i ++ ){
      printf( "%c", str1[i] );
    }
  }
}
