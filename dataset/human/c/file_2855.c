#include<stdio.h>

int main(void) {
  int k, s;
  int x, y, z;
  int ans = 0;

  scanf("%d %d", &k, &s);

  for (x = 0; x <= k; x++){
    for (y = 0; y <= k; y++){
      if (k >= s - x - y && s - x - y >= 0){
        ans++;
      }
    }
  }

  printf("%d\n", ans);
  return (0);
}
