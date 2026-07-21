#include<stdio.h>

int main()
{
	int K,N,A[200000],i,l,lx;

	scanf("%d%d",&K,&N);
	for (i = 0;i < N;i++)
	{
		scanf("%d",&A[i]);
	}


	lx = A[0] + K - A[N - 1];

	for (i = 1;i < N;i++)
	{
		l = A[i] - A[i - 1];
		if (l > lx)
		{
			lx = l;
		}

	}

	printf("%d\n",K - lx);
	return 0;

}
