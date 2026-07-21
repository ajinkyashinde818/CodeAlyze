#include <stdio.h>
int main()
{
	int N, K, S;
	scanf("%d%d%d", &N, &K, &S);
	int i = 1;
	for(i;i<=K;i++)
	{
		printf("%d ", S);
	}
	for(i;i<=N;i++)
	{
		if(S+1<=1000000000)
		    printf("%d", S+1);
		else printf("999999999");
		if(i!=N) printf(" ");
	}
	printf("\n");
	return 0;
}
