#include <stdio.h>

int main(void)
{
  int n;
  int a[20];
  int b;
  int c[19];
  int sum = 0;
  int i;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for(i = 0; i < n; i++) {
    scanf("%d", &b);
    sum += b;
  }
  for(i = 0; i < n-1; i++)
    scanf("%d", &c[i]);
  
  for(i = 0; i < n-1; i++) {
    if (a[i]+1 == a[i+1])
      sum += c[a[i]-1];
  }
  
  printf("%d", sum);
  
  return 0;
}
