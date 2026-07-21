#include<stdio.h>

int main(void)
{
	int r = 0;
	int g = 0;
	int b = 0;
	int n = 0;
	int c = 0;

	scanf("%d", &r);
	scanf("%d", &g);
	scanf("%d", &b);
	scanf("%d", &n);

	for (int i = 0; i <= n / r; i++)
	{
		for (int j = 0; j <= (n - i * r) / g; j++)
		{
			if((n-i*r-j*g)%b==0)
				{c++;  }	
			
		}
	}
	printf("%d", c);
	return 0;
}
