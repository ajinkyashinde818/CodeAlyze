#include <stdio.h>
int main(void)
{
	int r;
	int g;
	int b;
	int n;
	int x;
	int y;
	int temp;
	int res;

	scanf("%d%d%d%d", &r,&g,&b,&n);
	res = 0;
	x = 0;
	while (x <= n)
	{
		y = 0;
		while (y <= n)
		{
			temp = n - r*x - g*y;
			if (temp >= 0 && temp % b == 0)
			{
				res++;
			}
			y++;
		}
		x++;
	}
	printf("%d\n", res);
	return (0);
}
