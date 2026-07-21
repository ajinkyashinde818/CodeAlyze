// abc053c: X: Yet Another Die Game
#include <stdio.h>
#define in(a) scanf("%lld",(a))
#define out(a) printf("%lld\n",(a))

int main(){
  long x;in(&x);
  long c= (x/11)*2;
  x %= 11;
  // dice face 5 start: snuke-kun's favorite number
  if(x==0) out(c);
  else if(x<7) out(c+1);
  else out(c+2);
  return 0;
}
