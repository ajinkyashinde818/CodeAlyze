#include <stdio.h>
#include <iostream>

int main()
{
	int n;
	scanf("%d", &n);
	int R[200000];
	for (int i = 0; i < n; i++)
		scanf("%d", R + i);
	int max = (int)0x80000000;
	int min = R[0];
	for (int i = 1; i < n; i++)
	{
		if (R[i] - min > max)
			max = R[i] - min;
		if (R[i] < min)
			min = R[i];
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int diff = R[j] - R[i];
			if (diff > max)
			{
				max = diff;
			}
		}
	}
	//*/
	
	printf("%d\n", max);
    return 0;
}
