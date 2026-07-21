#include<stdio.h>

int main()
{
  int k = 0;
  int n = 0;
  int a[200000];
  int max = 0;
  int buf = 0;
  
  scanf("%d %d",&k,&n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d",&a[i]);
  }
  
  max = k -a[n-1] + a[0];
  for(int j = 0;j <( n -1);j++)
  {
    buf = a[j + 1]-a[j];
    if (buf > max)
    {
      max = buf;
    }
  }

  max = k-max;
  
  printf("%d",max);
    return 0;
}
