#include<stdio.h>
int main()
{
	int n, d, x, a, i, j, count;
	while(~scanf("%d %d %d", &n, &d, &x))
	{
		count = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &a);
			for(j=0; (j*a+1)<=d; j++) count++;
		}
		printf("%d\n", x+count);
	}
	return 0;
}
