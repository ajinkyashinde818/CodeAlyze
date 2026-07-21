#include <stdio.h>
int main(void)
{
	int x1=1,x[10000],i;
	for(i=0;x1 != 0;i++)
	{
		scanf("%d" , &x1);
		x[i] = x1;
	}
	
	for(i=0;x[i] != 0;i++)
	{
		printf("Case %d: %d\n",i+1,x[i]);
	}
	return 0;
}
