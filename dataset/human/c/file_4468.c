#include<stdio.h>

int main()
{
  int n;
  int a[100][2];
  int i;
  
  scanf("%d",&n);
  
  for(i=0;i<=n;i++)
  {
    scanf("%d %d",&a[i][1],&a[i][2]);
  }
  
  for(i=0;i<n-2;i++)
  {
    if(a[i][1]==a[i][2] && a[i+1][1]==a[i+1][2] &&  a[i+2][1]==a[i+2][2])
    {
      printf("Yes");
      return 0;
    }
  }
  printf("No");
  return 0;
}
