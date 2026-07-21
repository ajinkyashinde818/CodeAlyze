#include<stdio.h>

int main(void){
  int a, b, c, i, ans;
  scanf("%d %d %d", &a, &b, &c);
  i = ( a > b ) ? b : a;
  while ( c ) {
    if ( !(a % i) && !(b % i) ) {
      c -= 1;
      ans = i;
    }
    i--;
  }
  printf("%d\n", ans);
  return 0;
}
