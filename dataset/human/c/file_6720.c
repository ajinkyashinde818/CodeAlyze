#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, m;
	int i, j;
	int a, b;
	int count;
	int list[501][501];
	int friend[501];

	while (1){
		scanf("%d", &n);
		scanf("%d", &m);

		if (n == 0 && m == 0){
			break;
		}

		memset(list, 0, sizeof(list));
		memset(friend, 0, sizeof(friend));
		count = 0;

		for (i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			list[a][b] = 1;
			list[b][a] = 1;
		}

		for (i = 2; i <= n; i++){
			if (list[1][i] == 1){
				friend[i] = 1;

				for (j = 2; j <= n; j++){
					if (list[i][j] == 1){
						friend[j] = 1;
					}
				}
			}
		}

		for (i = 2; i <= n; i++){
			if (friend[i] == 1){
				count++;
			}
		}

		printf("%d\n", count);
	}

	return (0);
}
