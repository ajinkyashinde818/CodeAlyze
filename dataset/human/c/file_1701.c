#include <stdio.h>

int main(void)
{
  int n;
  scanf("%d", &n);
  int a[n];
  int b[n];
  int c[n-1];
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for(int i = 0; i < n - 1; i++) {
    scanf("%d", &c[i]);
  }

  int satisfied = b[a[0]];

  for(int i = 1; i < n; i++) {
    satisfied += b[a[i]];
    if(a[i] == a[i-1] + 1) {
      satisfied += c[a[i-1]];
    }
  }
  printf("%d\n", satisfied);
  return 0;
}
