#include <stdio.h>

int main(void)
{
	int x,y,z,a,b,c,k,s;
	a = 0;
	scanf("%d %d",&k,&s);
	for (x = 0; x<=k;x++)
	{
		for (y = 0; y <= k ; y++)
		{
//			printf("%d %d %d\n",x,y,s-x-y);
			if (s-x-y <= k && s-x-y >= 0) a++;
		}
	}
	printf("%d",a);
	return 0;
}
