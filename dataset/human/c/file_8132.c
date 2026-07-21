#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int a, b, c, d;
	int S;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);

	S = a * b;
	if (S < c * d) {
		S = c * d;
	}
	
	printf("%d\n", S);

	return (0);
}
