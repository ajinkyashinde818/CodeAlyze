#include<stdio.h>

int main()
{
  int n,d,x;
  
  scanf("%d%d%d",&n,&d,&x);
  
  int a[n];
  int i;
  
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  
  int ans;
  
  ans=x;
  
  for(i=0;i<n;i++)
  {
    int j=0;
    while(j*a[i]+1<=d)
    {
      ans+=1;
      j++;
    }
  }
  
  printf("%d\n",ans);
  
  return 0;
}
