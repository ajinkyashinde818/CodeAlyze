#include<stdio.h>
#include<string.h>

int  main()
{
  int n,m;
  char a[51][51]={},b[51][51]={};
  int i,j;
  int tmp=0;
  
  scanf("%d%d",&n,&m);
  
  for(i=0;i<n;i++)
  {
    scanf("%s",&a[i]);
  }
  
  for(i=0;i<m;i++)
  {
    scanf("%s",&b[i]);
  }
  
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      if(strstr(a[i],b[j])==NULL)
      {
        printf("No\n");
        return 0;
      }
        else
        {
          tmp=1;
        }
    }
  }

  
  if(tmp==1)
  {
    printf("Yes\n");
  }
  return 0;
}
