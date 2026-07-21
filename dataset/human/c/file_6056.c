#include <stdio.h>

int is_prime(int x)
{
	if(x == 1) { return 0; }
	if(x == 2) { return 1; }

	if(x % 2 == 0)
	{
		return 0;
	}
	
	for(int i = 3; i * i <= x; i += 2)
	{
		if(x % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	int n, r, d;
	int rmin = +2000000000;
	int dmax = -1000000000;
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &r);
		d = r - rmin;
		rmin = r < rmin ? r : rmin;
		dmax = d > dmax ? d : dmax; 
	}
	printf("%d\n", dmax);
}
