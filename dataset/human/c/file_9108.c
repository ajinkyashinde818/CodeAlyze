#include <stdio.h>
int main()
{
  int n,k;
  scanf("%d %d",&n,&k);
  int h=0;
  int count=0;
  for(int i=0; i<n; i++)
  {
    scanf("%d",&h);
    if(h>=k)count++;
  }
  printf("%d\n",count);
  return 0;
}
