#include<stdio.h>
int main(void)
{
	int i[10000],a,b;

	for (a = 0; a < 10000; a++)
	{
		scanf("%d", &i[a]);

		if (i[a] == 0)
			break;
	}

	for (b = 0; b < a; b++)
	{
		printf("Case %d: %d\n", b+1,i[b]);
	}

	return 0;

}
