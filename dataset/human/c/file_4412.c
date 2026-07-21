#include <stdio.h>

int main(void)
{
  int n;
  int d[200];
  int i, flag = 0, tmp = 0;

  scanf(" %d", &n);
  tmp = n;
  for(i = 0;0 != n--; i+=2)
    scanf(" %d %d", &d[i], &d[i + 1]);
  i = 0;
  while (tmp--)
  {
    if (d[i] == d[i + 1])
      flag++;
    else
      flag = 0;
    if (flag == 3)
    {
      printf("Yes\n");
      return (0) ;
    }
    i += 2;
  }
  printf("No\n");
  return (0);
}
