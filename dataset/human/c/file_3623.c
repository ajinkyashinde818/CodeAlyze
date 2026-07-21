#include <stdio.h>

int main()
{
	long int a, b, x, r,dum;

	scanf("%ld%ld", &a, &b);

	x = a * b;

	if (a < b)
	{
		dum = a;
		a = b;
		b = dum;
	}

	r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}

	printf("%ld\n", x / b);


	return 0;
}
