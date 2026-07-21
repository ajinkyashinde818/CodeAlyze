#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i,j,n, d, x, a[100],choco=0;

	scanf("%d%d%d", &n, &d, &x);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < d; j += a[i])
		{
			choco++;
		}
	}

	printf("%d\n", choco+x);

		return 0;
}
