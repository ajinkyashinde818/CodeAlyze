#include<stdio.h>


int main()
{
	int n;
	int amax;
	int C[200000];
	int cmin;

	scanf("%d", &n);
	for (int t = 0; t < n; t++)
	{
		scanf("%d", &C[t]);
	}

	amax = C[1] - C[0];
	cmin = C[0];
	
	for (int j = 0; j < n-1 ; j++)
	{

		if (C[j] <= cmin)
		{
			cmin = C[j];

		
		for (int i = j + 1; i < n; i++)
		{
			int comp = C[i] - cmin;
			if (amax < comp)
			{
				amax = comp;
			}
		}
	   }
	}
		printf("%d\n", amax);	
			

	return 0;
}
