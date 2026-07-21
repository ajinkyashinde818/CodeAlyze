#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int main()
{
	int n, a, b;
	scanf("%d", &n);
	int chk = 0;
	int occur = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		if (a == b) chk++;
		else chk = 0;
		if (chk >= 3) occur = 1;
	}
	if (occur) printf("Yes");
	else printf("No");
}
