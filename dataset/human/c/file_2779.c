#include<stdio.h>

int main(void)
{
  int k = 0,s = 0,z = 0,count = 0;
  scanf("%d%d",&k,&s);
  for(int x = 0;x <= k;++x)
  {
    for(int y = 0;y <= k;++y)
    {
      z = s - x - y;
      if(0 <= z && z <= k)
      {
        count++;
      }
    }
  }
  printf("%d",count);
  return 0;
}
