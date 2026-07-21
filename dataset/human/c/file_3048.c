#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>

int main()
{
	int k, n,max,w, * p;
	scanf("%d%d", &k, &n);
	p = (int*)calloc(n, sizeof(int));
	
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", p + i);
	}
	max = p[0] + k - p[n - 1];

	for (size_t i = 1; i < n; i++)
	{
		w = p[i] - p[i - 1];
		if (max < w) { max = w; }
	}

	printf("%d\n", k - max);

	return 0;
}
