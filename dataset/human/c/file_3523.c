#include <stdio.h>
#include <string.h>
#define MIN(x, y) (((x) > (y)) ? (y) : (x))
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))

int main()
{
  int n;
  long long k;
  scanf("%d%lld", &n,&k);
  int a[200001];
  char visited[200001] = {0};
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int rem = 0;
  int offset = 1;
  int next = 1;
  for (int i = 0; i < n * 2; i++) {
    visited[next]++;
    next = a[next];
    if (visited[next] == 1) {
      rem++;
    } else if (visited[next] == 2) {
      break;
    } else {
      offset++;
    }
  }
  //printf("%d, %d\n", offset, rem);
  int m = (k <= (long long)offset) ? k : (k - (offset + 1)) % rem + (offset + 1);
  //((k - (long long)offset) % (long long)(rem) + (long long)offset);
  next = 1;
  for (int i = 0; i < m; i++) {
    next = a[next];
  }
  printf("%d", next);
  return 0;
}
