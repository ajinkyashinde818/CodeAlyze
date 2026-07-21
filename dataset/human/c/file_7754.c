#include <stdio.h>
int main(void)
{
	int a, b, c, d, e;
	scanf("%d", &a);
	for (e = 1; e <= a; e++)
	{
		scanf("%d %d", &b, &c);
		d = b%c;
		if (d == 0)
			printf("%d\n", c);
		else
			printf("%d\n", d);
	}
	return 0;
	
}
