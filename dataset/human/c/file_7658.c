#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[10001], n;
	for(int i = 0 ; ; i++)
	{
		scanf("%d", &a[i]);
		if(a[i]==0)
		{
			n = i;
			break;
		}
	}
	for(int i = 0 ; i < n ; i++)
	{
		printf("Case %d: %d\n", i+1, a[i]);
	}
	return 0;
}
