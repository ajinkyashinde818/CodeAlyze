#include <stdio.h>
#include <stdlib.h>

int main(){

  int i,j,n,*r;
  int max,min;
  
  scanf("%d",&n);

  r=(int*)malloc(sizeof(int)*n);
  
  for(i = 0;i < n;i ++)
    {
      scanf("%d",&r[i]);
    }
  

  min = r[0];

  max = r[1]-r[0];

  for(i = 1;i < n;i ++)
    {
      if(max < r[i]-r[0])
	{
	  max = r[i] - r[0];
	}
    }
 
  for(i = 1;i < n-1;i ++)
    {
      if(r[i] < min)
	{
	  min = r[i];
	  for(j = i+1;j < n;j ++)
	    {
	      if(max < r[j]-r[i])max = r[j]-r[i];
	    }
	}
    }
 
  printf("%d\n",max);
  return 0;
}
