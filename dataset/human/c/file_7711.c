#include<stdio.h>
int main() {
  int x[10000], i = 0, j = 0;
  while(1){
    scanf("%d", &x[i]);
    if (x[i] == 0) {
      break;
    }
    i++;
  }
  for (; j < i; j++) {
    printf("Case %d: %d\n", j + 1, x[j]);
  }
  return 0;
}
