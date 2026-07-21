#include<stdio.h>
//abc120-A
/*
int main(void)
{
	int a, b, c,d;
	scanf("%d %d %d", &a, &b, &c);

	if (b >= a * c)
	{
		printf("%d", c);
	}

	else
	{
		d = b / a;
		printf("%d", d);
	}
	return 0;
}*/
//abc120-B
int main(void)
{
	int a, b, k, tmp;
	int ans = 0, i, j;

	scanf("%d %d %d", &a, &b, &k);

	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}

	for (i = b; i > 0; i--)
	{
		if ((a % i + b % i) == 0)
		{
			ans += 1;
		}
		if (ans == k)
		{
			break;
		}

	}
	printf("%d", i);
	return 0;
}
