#include <stdio.h>

int main(void)
{
	int A, B, K;
	int i, n;
	int counter = 0;

	scanf("%d %d %d", &A, &B, &K);


	if(A<=B)
	{
		n = A;
	}
	else
	{
		n = B;
	}


	for(i=n; i>0; i--)
	{
		if(A%i == 0 && B%i == 0)
		{
			counter++;
			if(counter == K) printf("%d", i);
		}
	}	

	return 0;
}
