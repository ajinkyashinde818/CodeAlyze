#include <stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int i = 0;
  int d[n][2];
  int cnt = 0;
  while (i < n)
  {
    scanf("%d",&d[i][0]);
    scanf("%d",&d[i][1]);
    if (d[i][0] == d[i][1])
      cnt++;
    else
      cnt = 0;
    if (cnt == 3)
    {
      printf("Yes");
      return (0);
    }
    i++;
  }
  printf("No");
}
