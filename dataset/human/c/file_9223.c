#include <stdio.h>

int main(void)
{
  int n, k;
  scanf("%d %d", &n, &k);
  int h[n];
  for (int i = 0; i < n; i++){
    scanf("%d", &h[i]);
  }
  
  int count = 0;
  for (int i = 0; i < n; i++){
    if (h[i] >= k) count++;
  }
  
  printf("%d\n", count);
  return 0;
}
