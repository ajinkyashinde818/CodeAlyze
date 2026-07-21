#include <stdio.h>;
//#include "Main.h"
int main(void)
{
	// Your code here!
	int n;
	int a[51];
	int b[51];
	int c[51];
	long int ans=0;

	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &b[i]);
		ans = ans + b[i];
	}
	for (int i = 0; i<n-1; i++)
	{
		scanf("%d", &c[i]);
	}
	for (int i = 0; i<n; i++)
	{
		if (a[i]+1 == a[i+1])
		{
			ans = ans + c[a[i]-1];
		}
	}
	printf("%ld", ans);
}
