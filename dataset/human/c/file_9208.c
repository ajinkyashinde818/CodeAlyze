#include<stdio.h>

int main(){
  int n,k,h[100001],count=0;
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++)
    {
      scanf("%d", &h[i]);
    }
  for(int i=0;i<n;i++)
    {
      if(h[i]>=k)
	{
	  count++; 
	}
    }
  printf("%d\n",count);
  return 0;
}
