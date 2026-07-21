#include <stdio.h>
int main(void)
{
	int a,b,c[10]={0},d;
	d=0;
	for (a=0;a<10;a++)
	{
		scanf("%d",&b);
		c[a]=b;
	}
	for (a=0;a<10;a++)
	{
		d=d+c[a];
	}
	printf("%d\n",d);
	return 0;
}
