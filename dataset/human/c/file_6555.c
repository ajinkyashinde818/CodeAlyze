#include<stdio.h>
#include<math.h>

int main(void){
	int N,i,j;
	scanf("%d",&N);
	int r[N],diff[N-1];
	for(i=0;i<N;i++)
	{
		scanf("%d",&r[i]);
	}
	
	int min=r[0];
	
	for(i=1;i<N;i++)
	{
		
		if(min>=r[i-1])
		{
			min=r[i-1];
		}
		for(j=0;j<i;j++)
		{
			diff[i-1]=r[i]-min;
			//printf("%d %d %d\n",diff[i-1],r[i],min);
		}
	}
	
	int max=diff[0];
	
	for(i=0;i<N-1;i++)
	{
		if(max<=diff[i])
		{
			max=diff[i];
		}
	}
	
	printf("%d\n",max);
	
	return 0;
}
