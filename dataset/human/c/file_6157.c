#include <stdio.h>

int main (void)
{
  int n, r, minr, max = -1000000000;
  
  scanf("%d %d", &n, &minr);
  
  while (--n) {
    scanf("%d", &r);
    if (r - minr > max)
      max = r - minr;
    if (r < minr)
      minr = r;
  }
  
  printf("%d\n", max);
  
  return 0;
}
