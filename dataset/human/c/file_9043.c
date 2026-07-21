#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int h;
    scanf("%d", &h);
    if (h >= K) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
