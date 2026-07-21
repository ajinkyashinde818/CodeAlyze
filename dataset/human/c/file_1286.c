#include<stdio.h>

int main()
{
	int i, j, k,sum, min;
	int arr[8][8] = {
		{ 1,2,1,2,1,4,1,4 },
		{ 1,2,1,4,1,4,1,2 },
		{ 1,4,1,2,1,2,1,4 },
		{ 1,4,1,4,1,2,1,2 },
		{ 2,1,2,1,4,1,4,1 },
		{ 2,1,4,1,4,1,2,1 },
		{ 4,1,2,1,2,1,4,1 },
		{ 4,1,4,1,2,1,2,1 },
	}, arr_p[8] = { 0 };

	while (scanf("%d %d %d %d %d %d %d %d", &arr_p[0], &arr_p[1], &arr_p[2], &arr_p[3], &arr_p[4], &arr_p[5], &arr_p[6], &arr_p[7]) != EOF)
	{
		min = -1;

		for (k = 0; k < 8; k++)
		{
			sum = 0;
			for (i = 0; i < 8; i++)
			{
				if (arr_p[i] > arr[k][i])
				{
					sum += arr_p[i] - arr[k][i];
				}
			}
			
			if (sum < min||min==-1)
			{
				min = sum;
				j = k;
			}
		}

		for (i = 0; i < 8; i++)
		{
			printf("%d",arr[j][i]);
			if (i != 7)
			{
				putchar(' ');
			}
			else
			{
				putchar('\n');
			}
		}

	}


	return 0;
}
