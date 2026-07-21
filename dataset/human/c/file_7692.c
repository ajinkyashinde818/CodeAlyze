#include<stdio.h>

int main()
{
  int arr[10000];
  int count=0;
  int n;
  int a=0;
  scanf("%d", &n);
  arr[count] = n;
  count++;
  while(n != 0)
    {
      scanf("%d", &n);
      arr[count] = n;
      count++;
    }
  while(a+1 < count)
    {
      printf("Case %d: %d\n", a+1, arr[a]);
      a++;
    }
  return 0;
}
