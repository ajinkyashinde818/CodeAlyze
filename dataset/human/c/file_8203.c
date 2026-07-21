#include <stdio.h>

int
main(void)
{
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);

	int rec1 = A * B;
	int rec2 = C * D;

	int res;
	if (rec1 > rec2)
		res = rec1;
	else if (rec1 < rec2)
		res = rec2;
	else
		res = rec1;

	printf("%d\n", res);
	return 0;
}
