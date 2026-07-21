#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n,m,x;
int ans=0;
int c[12]={0};
int a[12][12]={{0}};
int ability[12]={0};
int sel[12]={0};
int tmp;

void sum(int p[])
{
  tmp=0;
  for(int j=0;j<m;j++) ability[j]=0;
  for(int i=0;i<n;i++)
  {
    if(p[i]==1)
    {
      tmp+=c[i];
      for(int j=0;j<m;j++)
      {
        ability[j]+=a[i][j];
      }
    }
  }
}

void search(int i)
{
  for(int k=0;k<=1;k++)
  {
    sel[i]=k;
    if(i==n-1)
    {
      sum(sel);
      int flag=0;
      for(int j=0;j<m;j++)
      {
        if(ability[j]<x)
        {
          flag=1;
          break;
        }
      }
      if(flag==0 && ans>tmp) ans=tmp;
    }
    else search(i+1);
  }
}

int main(void)
{
  scanf("%d %d %d",&n,&m,&x);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&c[i]);
    ans+=c[i];
    for(int j=0;j<m;j++)
    {
      scanf("%d",&a[i][j]);
      ability[j]+=a[i][j];
    }
  }

  for(int j=0;j<m;j++)
  {
    if(ability[j]<x)
    {
      printf("-1\n");
      return 0;
    }
  }

  search(0);
  printf("%d\n",ans);

  return 0;
}
