#include <stdio.h>

int main(){
  int i, n, min, max, x, y;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){

    scanf("%d",&x);

    if(i == 0) y = x;

    if(i == 1) max = x - y;
    else if (max < x - min) max = x - min;

    if(i == 0) min = x;
    else if (min > x) min = x;
  }

  printf("%d\n", max);

  return 0;
}
