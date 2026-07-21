#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
	int N;
	int A[20];
	int B[50];
	int C[50];
	int sum = 0;
	int before=100;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < N; i++)
		scanf("%d", &B[i]);

	for (int i = 0; i < N-1; i++)
		scanf("%d", &C[i]);

	for (int i = 0; i < N; i++)
	{
		
		sum += B[A[i]-1];
		if (before + 1 == A[i])
			sum += C[before-1];
			
		before = A[i];
		//printf("%d\n", sum);

	}

	printf("%d", sum);

}
