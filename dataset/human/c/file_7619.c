#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input(int x[]);
int output(int x[]);

int main(void)
{
	int x[10000] = { 0 };

	input(x);
	output(x);

	return 0;
}
int input(int x[])
{
	for (int loop = 0;loop<10000;loop++)
	{
		scanf("%d", &x[loop]);

		if (0 == x[loop])
			break;
	}
	return 0;
}
int output(int x[])
{
	for (int loop = 0; loop<10000; loop++)
	{
		if (0 == x[loop])
			break;
		printf("Case %d: %d\n", loop + 1, x[loop]);
	}
	return 0;
}
