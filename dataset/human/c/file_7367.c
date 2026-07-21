#include<stdio.h>

int main()
{
	int num[10000];
	int i=0,j=0;
	do
	{
		scanf("%d",&num[i]);
		i++;
	}while(num[i-1] != 0);
	while(num[j] != 0)
	{
		printf("Case %d: %d\n",j+1,num[j]);
		j++;
	}
	return 0;
}
