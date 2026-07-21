#include<stdio.h>

#define MAX 10000
int main(void)
{
  int a[MAX];
  int i,j;

  for(i=0;i<MAX;i++)
    {
      scanf("%d",&a[i]);
      if(a[i]==0)
	break;
    }
  for(j=0;j<i;j++)
    {
      printf("Case %d: %d\n",j+1,a[j]);
    }
}
