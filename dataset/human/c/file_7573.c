#include <stdio.h>

#define DATA 10000

int main(void)
{
	int num[DATA];
	int i;

	for(i = 0;i < DATA;i++)
	{
		scanf("%d", &num[i]);
		if(num[i] == 0)
			break;
	}
	for(i = 0;num[i] != 0;i++)
		printf("Case %d: %d\n", i + 1, num[i]);

	return 0;
}
