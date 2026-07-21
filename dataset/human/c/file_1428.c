#include <stdio.h>
int main ()
{
	int n,a;
	while(scanf("%d",&n)!=EOF)
	{
		if(n >= 90)
		{
			printf("Yes\n");
		}
		else
		{
		a = n % 10;
		if(a == 9)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
		}
	}
	return 0;
}
