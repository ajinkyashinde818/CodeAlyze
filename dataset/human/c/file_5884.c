#include <stdio.h>

int min (int a, int b){
  if ( a > b ){
    return b;
  } else {
    return a;
  }
}

int max (int a, int b){
  if ( a < b ){
    return b;
  } else {
    return a;
  }
}

int main ()
{
 int a[200000];
 int ans, small, diff, x;

 scanf("%d", &x);

 for ( int i = 0; i < x; i++){
  scanf("%d", &a[i]);
 }

 small = a[0];
 diff  = a[1] - a[0];
 ans   = diff;

 for ( int j = 1; j < x; ++j){
   diff  = a[j] - small;
   ans   = max( ans,   diff );
   small = min( small, a[j] );
 }

 printf("%d\n", ans);

 return 0;
}
