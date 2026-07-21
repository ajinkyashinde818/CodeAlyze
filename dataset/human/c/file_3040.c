#include <stdio.h>

int main(void)
{
  int k, n;
  int a[200001] = {0};
  int max = 0;

  scanf("%d %d", &k, &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  for (int i = 1; i < n; i++){
    if (max < a[i] - a[i-1]) max = a[i] - a[i-1];
  }

  if (max < k - a[n-1] + a[0]) max = k - a[n-1] + a[0];
  

  printf("%d", k - max);

  return 0;
}
