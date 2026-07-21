#include <stdio.h>
int main(void)
{
	int i, x;
	i = 1;

	scanf("%d", &x);
	if (x != 0)
	{
		printf("Case 1: %d\n", x);
	}
	
	while(x != 0)
	{
		scanf("%d", &x);
		if ((1 <= x) && (x <= 10000))
		{
			i = i + 1;
			printf("Case %d: %d\n", i, x);
		}
		else break;
	}
	return 0;
}
