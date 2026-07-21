#include <stdio.h>
#include <string.h>

int main(void)
{
	int b[512];
	int friends[512][512];
	int i, j;
	int n, m;
	int from, to;
	int ans;
	
	while (1){
		memset(b, 0, sizeof(b));
		memset(friends, 0, sizeof(friends));

		scanf("%d %d", &n, &m);
		if (n == 0) break;
		
		for (i = 0; i < m; i++){
			scanf("%d %d", &from, &to);
			friends[from][to] = 1;
			friends[to][from] = 1;
		}

		for (i = 1; i <= n; i++){
			if (friends[1][i] == 1){
				b[i] = 1;
				for (j = 1; j <= n; j++){
					if (friends[i][j] == 1){
						b[j] = 1;
					}
				}
			}
		}

		ans = 0;
		for (i = 2; i <= n; i++){
			ans += b[i];
		}

		printf("%d\n", ans);
	}
	return (0);
}
