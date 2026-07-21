#include <stdio.h>

int main()
{
	int data[200000];
	int n;

//	int data[] = { 4,1,2,1 };
//	int n = 4;*
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	
	int max = -2000000000;
	int min = data[0];

	for (int i = 1; i < n; i++)
	{
		if (max < data[i] - min)
		{
			max = data[i] - min;
		}
		if (min > data[i])
		{
			min = data[i];
		}
	}

	printf("%d\n", max);
}
