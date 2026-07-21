#include <stdio.h>

int main(void)
{
  int k, s;
  int x, y, z;
  int count = 0;
  
  scanf("%d%d", &k, &s);
  
  for (x = 0; x <= k; x++) {
    for (y = 0; y <= k; y++) {
        z = s - x - y;
        if (z <= k && z >= 0)
          count++;
    }
  }
  printf("%d", count);
  return 0;
}
