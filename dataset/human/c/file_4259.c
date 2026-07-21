#include <stdio.h>
#include <stdlib.h>
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

typedef long long int64;

// void array_dump(int64 *arr, int len) {
//   for (int i = 0; i < len; i++) {
//     eprintf("arr[%d] = %d ", i, arr[i]);
//   }
//   eprintf("\n");
// }

int main(int argc, const char *argv[])
{
  int n, m;
  scanf("%d%d", &n, &m);
  // int64 *a = (int64 *)malloc((n + 1) * sizeof(int64));
  int64 a[100001];

  for (int i = 0; i <= n; i++) {
    // -1 means "not processing yet"
    a[i] = -1;
  }

  int tmp, ltmp = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", &tmp);
    if (tmp == ltmp - 1 || tmp == n ) {
      printf("0\n");
      return 0;
    }
    // 0 means broken stair
    a[tmp] = 0;
    ltmp = tmp;
  }

  a[0] = 1;
  if(a[1] == -1)
    a[1] = 1;

  for (int i = 2; i <= n; i++) {
    if(a[i] != -1)
      continue;
    a[i] = (a[i-1] + a[i-2])  % 1000000007;
  }
  // array_dump(a, n+1);
  // free(a);
  printf("%llu\n", a[n]);

  return 0;
}
