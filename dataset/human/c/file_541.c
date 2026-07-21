#include<stdio.h>
#include<stdlib.h>

int main()
{
  int  n, i;
  long  a[200000], x, y, min;

  scanf("%d", &n);

  x = 0L;
  y = 0L;
  for(i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
    y += a[i];
  }
  min = 1000000000000000L;
  for(i = 0; i < n-1; i++) {
    x += a[i]; 
    y -= a[i];
    if(labs(x - y) < min) {
      min = labs(x - y);
    }
  }
  printf("%ld\n", min);

  return 0;
}
