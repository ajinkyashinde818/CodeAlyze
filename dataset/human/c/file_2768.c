#include <stdio.h>
#include <math.h>

int main()
{
  int kk, ss;
  scanf("%d %d", &kk, &ss);
  int count = 0;
  for(int xx = 0;xx <= kk;xx++)
  {
    for(int yy = 0;yy <= kk;yy++)
    {
      int zz = ss - xx - yy;
      if(zz >= 0 && zz <= kk)
        count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
