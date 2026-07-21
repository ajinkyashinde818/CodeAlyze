#include <stdio.h>
#include <string.h>
int main()
{
	int n, m;
	int z[101];
	int i, j, tmp;
	scanf("%d%d", &n, &m);
	for (i = 1;i <= n;i++)scanf("%d", &z[i]);
	for (i = 1;i <= m;i++) {
		j = 1;
		while (j != n) {
			if (z[j] % i > z[j + 1] % i) {
				tmp = z[j];z[j] = z[j + 1];z[j + 1] = tmp;j++;
			}
			else if (z[j] % i <= z[j + 1] % i) j++;
		}
	}
	for (i = 1;i <= n;i++)printf("%d\n", z[i]);
	return 0;
}
