#include <stdio.h>
#include <stdint.h>

int getNumsInt32(int32_t *buf, int32_t num)
{
  int32_t i;

  for (i = 0; i < num; i++) {
    if (scanf("%d", &buf[i]) == EOF) {
      return -1;
    }
  }
  return 0;
}

int main()
{
  int32_t K, N, i;
  char s[10 + 1];

  if (getNumsInt32((int32_t *)&N, (int32_t)1) == -1) {
    return -1;
  }

  if (scanf("%s", s) == EOF) {
    return -1;
  }

  if (getNumsInt32((int32_t *)&K, (int32_t)1) == -1) {
    return -1;
  }
  
  for (i = 0; i < N; i++) {
    if (s[i] != s[K - 1]) {
      s[i] = '*';
    }
  }

  printf("%s\n", s);

  return 0;
}
