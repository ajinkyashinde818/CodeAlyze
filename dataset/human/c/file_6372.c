#include <stdio.h>

int main(void){
  int i, n, r, minv, maxv;
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    if (i == 0)
      scanf("%d", &minv);
    else {
      scanf("%d", &r);
      if (i == 1)
	maxv = r - minv;
      if (maxv < r - minv)
	maxv = r - minv;
      if (r < minv)
	minv = r;
    }
  }

  printf("%d\n", maxv);
  return 0;
}
