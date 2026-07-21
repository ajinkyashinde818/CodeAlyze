#include <stdio.h>
int main()
{
  int count=0,x,tray[10000];
  for(x=0;x<10000;x++)
  {
    count++;
    scanf("%d",&tray[x]);
    if(tray[x]==0)break;
    else printf("Case %d: %d\n",count,tray[x]);
  }
  return 0;
}
