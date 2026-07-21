#include <stdio.h>
#include <limits.h>

int main(void)
{
  long x;
  long y;
  long i, j;
  long tmp;

  scanf("%ld", &x);
  i = 0;
  j = 0;
  tmp = x%11;
  if(tmp == 0) {
    j = 0;
  } else if(tmp < 7) {
    j = 1;
  } else {
    j = 2;
  }
  i = (x/11)*2 +j;

  printf("%ld\n", i);
  return 0;
}
