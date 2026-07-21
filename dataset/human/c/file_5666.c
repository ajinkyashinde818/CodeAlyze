#include<stdio.h>

int max(int a, int b)
{
	return a>b ? a: b;
}

int min(int a, int b)
{
	return a<b ? a: b;
}
int main()
{
	int a[200000];
	int n, maxv, minv;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	maxv = -2000000000;
	minv = a[0];
	for(int i =1; i < n; i++)
	{
		
		maxv = max(maxv, a[i] - minv);
		minv = min(minv, a[i]);
	}
	printf("%d\n", maxv);
	return 0;
}
