#include <stdio.h>
#include <stdlib.h>

#define ABS(a) (((a) < 0) ? -(a) : (a) )

void solve(long *arr, int len) {
  long sum = 0, min = 1e9 + 100; 
  int i, n_cnt = 0;
  for(i = 0; i < len; ++i) {
    sum += ABS(arr[i]);
    if(arr[i] < 0) { ++n_cnt; }
    if(ABS(arr[i]) < min) { min = ABS(arr[i]); }
  }
  if(n_cnt % 2 != 0) { sum -= (2 * min); }
  printf("%ld\n", sum);
}

int main()
{
  int n, i;
  scanf("%d", &n);
  long *a = (long*)malloc((n+4)*sizeof(long));
  for(i = 0; i < n; ++i) { scanf("%ld", &a[i]); }
  solve(a, n);
  return 0;
}
