#include <stdio.h>

int k, s;

int main() {
  scanf("%d%d", &k, &s);
  int count = 0;
  for(int x = 0; x <= k; x++) {
    for(int y = 0; y <= k; y++) {
      if(s - x - y >= 0 && s - x - y <= k) count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
