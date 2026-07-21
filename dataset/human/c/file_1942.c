#include <stdio.h>

void insert(int len, int a[len]);

int main()
{
  int n;
  scanf("%d",&n);
  int a[n];
  int b[n];
  int c[n-1];
  insert(n, a);
  insert(n, b);
  insert(n-1, c);
  int i;
  i = 0;
  int satisfaction;
  satisfaction = 0;
  while (i < n)
  {
    satisfaction += b[a[i] - 1];
    if (i != n-1 && a[i] + 1 == a[i + 1])
    {
      satisfaction += c[a[i] - 1];
    }
    i++;
  }
  printf("%d",satisfaction);
}

void insert(int len, int a[len])
{
  int i;
  i = 0;
  while (i < len)
  {
    scanf("%d",&a[i]);
    i++;
  }
}
