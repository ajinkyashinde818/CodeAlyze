#include <stdio.h>

int main(void){

  int n;
  scanf("%d", &n);
  int a[n+1];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  int light = 1;
  int check[n+1];
  check[1] = 1;
  for (int i = 2; i <= n; i++) {
    check[i] = 0;
  }

  int count = 0;

  while (count < n) {
    count++;
    light = a[light];
    check[light]++;
    if (check[light] > 1) {
      printf("-1\n");
      break;
    }
    if (check[2] == 1) {
      printf("%d\n", count);
      break;
    }
  }

  return 0;
}
