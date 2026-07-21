#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i, j, n, maxDiff = -1000000000;
  int r[200000];
  int num, diff, min;

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &r[i]);
  }

  min = r[0];
  for(i = 1; i < n; i ++) {
    num = r[i];
    diff = num - min;
    if(diff > maxDiff) maxDiff = diff;
    if(num < min) min = num;
  }

  printf("%d\n", maxDiff);

  return 0;
}
