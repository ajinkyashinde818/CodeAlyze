#include <stdio.h>
int main(void)
{
	int a,b,c,d,e,f,g;
	scanf("%d %d",&a,&b);
	if (a==0)
	{
		if (1868<=b&&b<=1911)
		{
			c=b-1867;
			printf("M%d\n",c);
		}
		else if (1912<=b&&b<=1925)
		{
			c=b-1911;
			printf("T%d\n",c);
		}
		else if (1926<=b&&b<=1988)
		{
			c=b-1925;
			printf("S%d\n",c);
		}
		else if (1989<=b&&b<=2016)
		{
			c=b-1988;
			printf("H%d\n",c);
		}
	}
	if (a==1)
	{
		c=1867+b;
		printf("%d\n",c);
	}
	if (a==2)
	{
		c=1911+b;
		printf("%d\n",c);
	}
	if (a==3)
	{
		c=1925+b;
		printf("%d\n",c);
	}
	if (a==4)
	{
		c=1988+b;
		printf("%d\n",c);
	}
	return 0;
}
