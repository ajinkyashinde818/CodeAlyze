#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int d[102][2];
	for (i = 0; i < n; i++)
		scanf("%d %d", &d[i][0], &d[i][1]);
	int c = 0;
	for (i = 0; i < n - 2; i++)
		if (d[i][0] == d[i][1] && d[i + 1][0] == d[i + 1][1] && d[i + 2][0] == d[i + 2][1])
			c++;
	if (c > 0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
