#include <stdio.h>

int main(void){

  int k,s;
  scanf("%d %d", &k, &s);
  int count = 0;
  int z;
  for (int x = 0; x <= k; x++) {
    for (int y = 0; y <= k; y++) {
      z = s-x-y;
      if (z >= 0 && z <= k) {
        count++;
      }
    }
  }
  printf("%d\n", count);

  return 0;
}
