#include <stdio.h>


int main()
{
	int A, B, C, D;
	int square1, square2;


	scanf("%d %d %d %d", &A, &B, &C, &D);

	square1 = A * B;
	square2 = C * D;

	if(square1 > square2)
		printf("%d\n", square1);
	else if(square2 > square1)
		printf("%d\n", square2);
	else
		printf("%d\n", square1);

	return 0;
}
