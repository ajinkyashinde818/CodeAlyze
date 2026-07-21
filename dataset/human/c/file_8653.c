#include<stdio.h>

int main()
{
  int n;
  
  scanf("%d",&n);
  
  int a[n];
  int i;
  
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  
  int two=1;
  for(i=1;i<=n;i++)
  {
    two=a[two-1];
    if(two==2)
    {
      printf("%d\n",i);
      return 0;
    }
  }
  if(two!=2)
  {
    printf("-1\n");
  }
  return 0;
}
