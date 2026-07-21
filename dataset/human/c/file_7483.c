#include<stdio.h>

int main() {

	int a[10000], b=1, c=1;

	scanf("%d", &a[1]);
	if(a[1] != 0)
	{
		for (b = 2; a[b - 1] != 0; b++, c++)
		{
			scanf("%d", &a[b]);
		}

		for (b = 1; b < c; b++)
		{
			printf("Case %d: %d\n", b, a[b]);
		}
	}
	return 0;
}
