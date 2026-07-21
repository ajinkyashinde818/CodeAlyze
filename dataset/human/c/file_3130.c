#include <stdio.h>
#include <stdlib.h>

void input(int*, int);

#define MAX 200100

int main()
{
	int k, n;
	int data[MAX];
	int sum, max;
	int i, m;
	int dif;

	sum = max = 0;

	scanf("%d %d", &k, &n);
	input(data,n);

	for (i = 0, m=i+1; i < n; i++,m++)
	{
		if (m == n)
			m = 0;

		dif = abs(data[i] - data[m]);
		sum += dif;

		if (max < dif)
			max = dif;
		
		data[i] += k;
	}

	printf("%d\n", sum - max);

	return 0;
}

void input(int *data, int n)
{
	for (int i = 0; i < n; i++) 
		scanf("%d", &data[i]);
}
