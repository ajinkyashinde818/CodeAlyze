# include <stdio.h>
int main()
{
	int a[200000];
	int n;
	int max = -1000000000;
	

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		int tem;
		if ( a[i-1] < min)	min = a[i - 1];
		tem = a[i] - min;
	
		if( tem > max)   max = tem;
	}
	printf("%d\n",max);
 }
