#include<stdio.h>
int main()
{
	int A, B, K,i,j=0;
	int yakusuu[100];
	scanf("%d %d %d", &A, &B, &K);
	for (i = 1;i<=100;i++)
	{
		if ((A%i== 0 )&& (B%i == 0))
		{
			yakusuu[j] = i;
			j++;
		}
	}
	printf("%d\n", yakusuu[j - K]);
	return 0;
}
