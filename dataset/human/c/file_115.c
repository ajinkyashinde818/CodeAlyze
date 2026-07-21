#include <stdio.h>

int
main(int argc, char *argv[])
{
  int r, g, b, n, x, y, cnt = 0;
  scanf("%d %d %d %d", &r, &g, &b, &n);
  
  for(x = 0; x <= n / r; x++){
    for(y = 0; y <= (n - r * x) / g; y++){
      if((n - r * x - g * y) % b == 0) cnt++;
    }
  }
  
  printf("%d\n", cnt);
  
  return 0;
}
