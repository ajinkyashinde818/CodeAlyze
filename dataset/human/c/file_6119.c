#include<stdio.h>

int main(void)
{
	int i;
	int N;
	int data[200000];
	int max,min,now;
	scanf("%d",&N);

	for(i=0;i<N;i++)
	{
		scanf("%d",&data[i]);
	}
	max=data[1]-data[0];
	min=data[0];
	for(i=1;i<N;i++)
	{
		now=data[i]-min;
		if(max<now)
		{
			max=now;
		}
		if(min>data[i])
		{
			min=data[i];
		}
	}
	printf("%d\n",max);

	return 0;
}
