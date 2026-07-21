#include<stdio.h>
int main()
{
	int a, b, c, d, e;
	while(1)
	{
		scanf("%d %d",&a, &b);
		if (a==0&&b==0) break;
		c=1;
		e=1;
		for (d=0;d<a;d++)
		{
		if (d%2==1) while (e<=b)
		{
			if (e%2==0) printf("#");
			else printf(".");
			e++;
		}
		e=1;
		if (d%2==0) while(c<=b)
		{
			if (c%2==0) printf(".");
			else printf("#");
			c++;
		}
		c=1;
		printf("\n");
		}
		printf("\n");
	}
		return 0;
}
