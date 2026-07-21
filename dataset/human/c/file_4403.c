#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  int count = 0;
  for(int i = 0;i < n;i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if(a == b) {
      count++;
    } else {
      count = 0;
    }
    if(count == 3) {
      break;
    }
  }
  printf(count == 3 ? "Yes" : "No");
  puts("");
  return 0;
}
