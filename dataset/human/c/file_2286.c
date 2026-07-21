#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b

int main(void)
{
	int x;
	char *w;

	scanf("%d", &x);

	if (x < 1200) w = "ABC";
	else w = "ARC";

	printf("%s\n", w);

	return (0);
}
