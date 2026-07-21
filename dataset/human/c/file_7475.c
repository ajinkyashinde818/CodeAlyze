#include<stdio.h>

int main(void)
{
	int a[10000], i, count = 0;
	for(i=0; i<10000; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == 0)
			break;
		count++;
	}

	for(i=0; i<count; i++)
	{
		printf("Case %d: %d\n", i+1, a[i]);
	}

	return 0;
}
