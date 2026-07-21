#include<stdio.h>

int main(void) {
  int n, d, x, i, j;
  scanf("%d %d %d", &n, &d, &x);

  int a[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (j = 0; j < n; j++) {
    for (i = 1; i <= d; i += a[j]) {
      x++;
    }
  }
  printf("%d\n", x);
  
  return 0;
}
