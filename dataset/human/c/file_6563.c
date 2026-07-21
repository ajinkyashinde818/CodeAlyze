#include <stdio.h>
int main(void)
{

	int i, j, r[200000], d, rmin, dmax, k;
	scanf("%d",&i);

	for (j = 0; j < i; j++)
	{
		scanf("%d",&r[j]);
	}

	rmin = r[0];
	dmax = r[1] - r[0];
	for (j = 1; j < i; j++)
	{	
		
		if (dmax < r[j] - rmin)
		{
			dmax = r[j] - rmin;
		}
		if (rmin > r[j])
		{
			rmin = r[j];
		}
		

		//printf("dmax:%d, rmin:%d\n", dmax, rmin );
		
	}

	printf("%d\n", dmax);
	
	return 0;
}
