#include<stdio.h>
int main()
{
	int n,r[200000],min,k;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		scanf("%d",&r[i]);
	}
	k = r[1] - r[0];
	min = r[0];
	for (int i = 0; i < n -1; ++i)
	{
		if (min > r[i])
		{
			min = r[i];
		} 
		if (k <  r[i + 1] - min)
		{
			k = r[i + 1] - min;
		}
		
	}
	printf("%d\n",k);
	return 0;
}
