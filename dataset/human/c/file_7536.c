#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[100000], i, I;
	for(i = 0 ;  ; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == 0)
		{
			for(I = 0 ; I < i ; I++)
			{
				printf("Case %d: %d\n", I+1, a[I]);
			}
			exit(0);
		}
	}
	return 0;
}
