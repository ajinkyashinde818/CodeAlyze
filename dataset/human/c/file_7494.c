#include <stdio.h>

int main(void)
{
	int x;
	int i = 0;
	for( i=0; i<10000; i++ )
	{
		scanf("%d", &x);
		if( x<1 || x>10000)
		{
			return 1;
		}
		if( x == 0 )
		{
			break;
		}

		printf("Case %d: %d\n", i+1, x);
	}
	return 0;
}
