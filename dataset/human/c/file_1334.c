#include<stdio.h>
#define SIZE 200000
int main()
{
  int n,m;
  int a[SIZE],b[SIZE];
  int i,x,y;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++) a[i]=b[i]=0;
  for(i=0;i<m;i++)
    {
      scanf("%d%d",&x,&y);
      if(x==1) a[y-1]=1;
      if(y==n) b[x-1]=1;
    }
  for(i=0;i<n;i++)
    {
      if((a[i]==1)&&(b[i]==1))
	{
	  printf("POSSIBLE\n");
	  break;
	}
    }
  if(i==n) printf("IMPOSSIBLE\n");
  return 0;
}
