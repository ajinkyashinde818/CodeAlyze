#include<stdio.h>
int main()
{
	int a, b, k,i,s=0;
	scanf("%d %d %d", &a, &b, &k);
	if (a >= 1 && a <= 100 && b >= 1 && b <= 100 && k >= 1)
	{
		for (i = b;i > 0;i--)
		{
			if (a%i == 0 && b%i == 0)
			{
				s++;
				if (s == k)
				{
					printf("%d\n", i);
				}
			}
		}
	}
}
