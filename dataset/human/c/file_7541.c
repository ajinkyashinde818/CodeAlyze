#include <stdio.h>

int main(void)
{
	int suuji,i;
	i = 1, suuji = 1;

	while (0 <= suuji,i && suuji,i <= 10000 && suuji != 0)
	{
		scanf("%d", &suuji);

		if (0 <= suuji && suuji <= 10000 && suuji != 0)
		{
			printf("Case %d: %d\n", i, suuji);
			i++;
		}
		else
		{
			break;
		}
		
	}
	return 0;
}
