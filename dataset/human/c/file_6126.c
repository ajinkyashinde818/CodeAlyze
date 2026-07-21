#include <stdio.h>

int  main() {
  int n, i;
  long input;
  long minv;
  long maxv;

  scanf("%d", &n);
  
  scanf("%ld", &input);
  minv = input;
  
  for (i = 1; i < n; i++) {
    scanf("%ld", &input);

    if (i == 1) maxv = input - minv;
    
    maxv = (maxv > input - minv) ? maxv : input - minv;
    minv = (minv < input) ? minv : input;

  }
  printf("%d\n", maxv);
  
  return 0;
}
