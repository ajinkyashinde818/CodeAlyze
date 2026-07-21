#include<stdio.h>

int main()
{
  int j,N,R[200000],maxv,minv;

  scanf("%d",&N);
  for(j=0;j<N;j++){
    scanf("%d",&R[j]);
  }
  minv=R[0];
  maxv=R[1]-R[0];
  for(j=1;j<N;j++)
    {      
      if(maxv<R[j]-minv)
	{
	  maxv=R[j]-minv;
	}
	  
      if(minv>R[j])
	{
	  minv=R[j];
	}
    }
    
  printf("%d\n",maxv);
  return 0;
}
