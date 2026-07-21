#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j, l;
	int count = 0;
	int n, m;
	scanf("%d %d", &n, &m);

	char N[100][100];
	char M[100][100];

	for (i = 0; i < n; i++)
		scanf("%s", N[i]);
	for (i = 0; i < m; i++)
		scanf("%s", M[i]);

	if (n >= m)
		for (i = 0; i < n-m+1; i++)
		{
				for (j = 0; j < n-m+1; j++)
				{
					if (strncmp(N[i]+j, M[0], m) == 0)
					{
						count++;
						for (l = i+1 ; l < m+i; l++)
						{
							if (strncmp(N[l]+j, M[l-i], m) == 0)
								count++;
						}

						if (count == m)
						{
							printf("Yes"); return 0;
						}
						count = 0;
					}
				}
		}

	else if (m >= n)
		for (i = 0; i < m-n+1; i++)
		{
				for (j = 0; j < m-n+1; j++)
				{
					if (strncmp(N[i]+j, M[0], n) == 0)
					{
						count++;
						for (l = i+1 ; l < n+i; l++)
						{
							if (strncmp(N[l]+j, M[l-i], n) == 0)
								count++;
						}

						if (count == n)
						{
							printf("Yes"); return 0;
						}
						count = 0;
					}
				}
		}

	printf("No");

	return 0;
}
