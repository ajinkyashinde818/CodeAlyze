#include <stdio.h>

int main()
{
	int i,N,D,X,A;
	scanf("%d",&N);
	scanf("%d %d",&D, &X);
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&A);
		X += (D-1)/A + 1;
	}
	
	printf("%d\n", X);
	return 0;
}
