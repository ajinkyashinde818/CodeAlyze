#include <stdio.h>

#if 1
    #define gc() getchar_unlocked()
#else
    #define gc() getchar()
#endif

int in() {
    int n = 0, c = gc();
    do n *= 10, n += (c & 0xf), c = gc(); while (c >= '0');
    return n;
}


int main(void){
  int a, b, c;
  a = in(); b = in(); c = in();
  if (a + b + 1 >= c) printf("%d\n", c + b);
  else printf("%d\n", a + b + 1 + b);
}
