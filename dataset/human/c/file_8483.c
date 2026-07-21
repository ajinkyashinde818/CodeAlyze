#include<stdio.h>

#define N 10

int main(void)
{
  int i,j,tmp=0,k,l,n,S;
  int a[N][5];

  while(1)
    {
      scanf("%d",&n);
      if(n==0) break;
      for(i=0;i<=n-1;i++)
	{
	  for(j=0;j<=4;j++)
	    {
	      scanf("%d",&a[i][j]);
	    }
	}
      k=0;
      S=0;
      while(k!=n)
	{
	  k=0;
          for(i=n-1;i>=0;i--)
	    {
	      if(a[i][0]==a[i][1] && a[i][1]==a[i][2] && a[i][0]!=0)
	        {
	          if(a[i][2]==a[i][3])
		    {
		      if(a[i][3]==a[i][4])
		        {
		          for(j=0;j<=4;j++)
			    {
			      S+=a[i][j];
			      a[i][j]=0;
			    }
		        }
		      else
		        {
		          for(j=0;j<=3;j++)
			    {
			      S+=a[i][j];
			      a[i][j]=0;
			    }
		        }
		    }
	          else
		    {
		      for(j=0;j<=2;j++)
		        {
			  S+=a[i][j];
		          a[i][j]=0;
		        }
		    }
	        }
	      else if(a[i][0]!=a[i][1] && a[i][1]==a[i][2] && a[i][2]==a[i][3] && a[i][1]!=0)
	        {
	          if(a[i][3]==a[i][4])
		    {
		      for(j=1;j<=4;j++)
		        {
			  S+=a[i][j];
		          a[i][j]=0;
		        }
		    }
	          else
	            {
	              for(j=1;j<=3;j++)
		        {
			  S+=a[i][j];
		          a[i][j]=0;
		        }
		    }
	        }
	      else if(a[i][1]!=a[i][2] && a[i][2]==a[i][3] && a[i][3]==a[i][4] && a[i][2]!=0)
	        {
	          for(j=2;j<=4;j++)
		    {
		      S+=a[i][j];
		      a[i][j]=0;
		    }
	        }
	      else
		{
		  k++;
		}
	    }
          if(k<=n-1)
	    {
	      for(l=1;l<=n;l++)
		{
                  for(j=0;j<=4;j++)
	            {
	              for(i=1;i<=n-1;i++)
	                {
	                  if(a[i][j]==0)
		            {
		              tmp=a[i][j];
		              a[i][j]=a[i-1][j];
		              a[i-1][j]=tmp;
		            }
	                }
	            }
		}
	    }
	}
      printf("%d\n",S);
    }
  return 0;
}
