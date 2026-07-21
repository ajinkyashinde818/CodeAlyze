#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  char S[2000];
  int i, N, D1, D2, ans = 0;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d %d", &D1, &D2);
    if (D1 == D2) ans++;
    else          ans = 0;
    if (ans >= 3) {
      printf("Yes");
      return 0;
    }
  }
  printf("No");
  return 0;
}
