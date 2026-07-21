#include <stdio.h>
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif
void arrdump(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    printf("[%d] = %d\n", i, arr[i]);
  }
}

int main(int argc, const char *argv[])
{
  int a, b, k;
  int c[101] = {0};
  scanf("%d%d%d", &a, &b, &k);
  int m =  min(a, b);
  for (int i = 1; i <= m; i++) {
    if (a % i == 0 && b % i == 0)
      c[i]++;
  }
  // arrdump(c, m + 1);
  for (int i = m; i > 0; i--) {
    if (c[i] == 1) {
      k--;
      eprintf("c[%d] = %d, k = %d\n", i, c[i], k);
    }
    if (k == 0) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
