#include<stdio.h>

int main(void)
{
  int n,m,i,j,k,l,frag=1,s=0,t=0;
  char a[51][51],b[51][51];
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)
    {
      scanf("%s",a[i]);
    }
  for(i=0;i<m;i++)
    {
      scanf("%s",b[i]);
    }
  for(i=0;i<=n-m;i++)
    {
      for(j=0;j<=n-m;j++)
	{
	  s=0;
	  for(k=i;k<m+i;k++)
	    {
	      frag = 1; t=0;
	      for(l=j;l<m+j;l++)
		{
		  if(b[s][t] != a[k][l])
		    {
		      frag = 0;
		      break;
		    }
		  t++;
		}
	      if(frag == 0)
		{
		  break;
		}
	      s++;
	    }
	  if(frag == 1)
	    {
	      printf("Yes\n");
	      return 0;
	    }
	}
    }
  printf("No\n");
  return 0;
}
