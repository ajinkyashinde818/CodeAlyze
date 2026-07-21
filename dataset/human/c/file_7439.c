#include <stdio.h>

int main(void)
{
	int i,j;
	int a[99999];

	for(i=0;i<99999;i++)
		a[i]=1;

	i=0;

	while(!(a[i]==0))
	{
		i++;

		scanf("%d",&a[i]);		
	}

	j=i;
	i=1;

	while(!(i==j))
	{
		printf("Case %d: %d\n",i,a[i]);

		i++;

	}

	return 0;
}
