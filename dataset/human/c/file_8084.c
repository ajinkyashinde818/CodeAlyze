#include <stdio.h>

void bigarea(int A, int B, int C, int D)
{
	int areaA, areaB;
	areaA = A*B;
	areaB = C*D;
	if (areaA == areaB)
	{
		printf("%d\n", areaA);
	}
	else if (areaA > areaB)
	{
		printf("%d\n", areaA);
	}
	else
	{
		printf("%d\n", areaB);
	}
}

int main(void)
{
	int A, B, C, D;

	scanf("%d %d %d %d", &A, &B, &C, &D);

	bigarea(A, B, C, D);

	return 0;
}
