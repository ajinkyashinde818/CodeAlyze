#include <stdio.h>

int main(void)
{
	for(;;)
	{
		int a,n;
		scanf("%d",&a);
		if(a==0)
		{
			break;
		}
		for(n=0;;n++)
		{
			if(a==1)
			{
				break;
			}
			else if(a%2==1)
			{
				a=a*3+1;
			}
			else if(a%2==0)
			{
				a=a/2;
			}
		}
		printf("%d\n",n);
	}
	return 0;
}
