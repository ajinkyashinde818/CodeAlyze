#include<stdio.h>
#include<stdlib.h>
int main() {
	int n, m;
	scanf("%d %d",&n,&m);
	int i;
	char** a = malloc(sizeof(char*) * n);
	char** b = malloc(sizeof(char*) * m);
	for ( i = 0; i < n; i++)
	{
		a[i] = malloc(sizeof(char) * (n + 1));
		scanf("%s", a[i]);
	}
	for (i = 0; i < m; i++)
	{
		b[i] = malloc(sizeof(char) * (m + 1));
		scanf("%s", b[i]);
	}
	int j, k, l;
	int count;
	for ( i = 0; i < n-m+1; i++)
	{
		for (j = 0; j < n - m + 1; j++)
		{
			count = 0;
			for ( k = 0; k < m; k++)
			{
				for ( l = 0; l < m; l++)
				{
					if (a[i + k][j + l] != b[k][l])
						goto out;
					count++;
					if (count == m * m) {
						printf("Yes");
						return 0;
					}
				}
			}
		out:;
		}
	}
	printf("No");
}
