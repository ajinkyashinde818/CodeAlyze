#include <stdio.h>

int main()
{
  int n,k;
  int i;
  int h;
  int count=0;
  
  scanf("%d %d",&n,&k);
  
  for(i=0;i<n;i++)
  {
    scanf("%d",&h);
    if(h>=k)
    {
      count++;
    }
  }
  
    
    printf("%d",count);
    
    return 0;
}
