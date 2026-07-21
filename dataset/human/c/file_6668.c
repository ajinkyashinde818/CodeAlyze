#include <stdio.h>

int main()
{
  int n,i;
  int x,y;
  int max=0;
  scanf("%d",&n);
  scanf("%d",&x);
  scanf("%d",&y);
  max=y-x;
  if(x>y) x=y;
  for(i=2;i<n;i++){
    scanf("%d",&y);
    if(max<(y-x)) max=y-x;
    if(x>y) x=y;
  }

  printf("%d\n",max);
  return 0;
}
