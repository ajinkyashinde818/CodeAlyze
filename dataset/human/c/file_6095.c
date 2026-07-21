#include <stdio.h>
int main()
{
  int n,i,j,array[200000],maxv,minv;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&array[i]);
    }

  maxv=array[1]-array[0];
  minv=array[0];

  for(j=1;j<n;j++)
    {
      if(maxv < array[j]-minv)
	{
	  maxv=array[j]-minv;
	}
      if(minv > array[j])
	{
	  minv=array[j];
	}
    }

  printf("%d\n",maxv);

  return 0;
}
