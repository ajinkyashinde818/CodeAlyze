#include <stdio.h>

int main(void)
{
	int n,i,min,max,k;
	
	scanf("%d",&n);
	
	int R[n];
	
	for(i=0; i<n; i++)
	{
		scanf("%d",&R[i]);
	}
	
	min=R[0];
	max=R[1]-R[0];
	
	for(i=0; i<n; i++)
	{
		if(R[i]<min)
		{
			min=R[i];
		}
		
		if(i !=n-1)
		{
		    
		k=R[i+1]-min;
		if(k>max)
		{
			max=k;
		}
		}
	}
	
	printf("%d\n",max);
	
	return 0;
	
}
