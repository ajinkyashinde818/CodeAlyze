#include<stdio.h>
int main()
{
	int i,a[9999];
	for  (i = 0; ; (i++))
	{
		scanf("%d", &a[i]);
		if (a[i] == 0)
			break;
	}
	for ( i = 0;; i++)
	{
		if (a[i] == 0)
			break;
		else		
			printf("Case %d: %d\n", i+1, a[i]);
	}
	return 0;
}
