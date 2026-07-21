#include <stdio.h>

int main(void)
{
	int n, m;
	int a, b;
	int student[501][501];
	int i, j;
	int invite;
	int friends[501];
	
	while (scanf("%d %d", &n, &m)){
		invite = 0;
		for (i = 0; i < 501; i++){
			friends[i] = 0;
			for (j = 0; j < 501; j++){
				student[i][j] = 0;
			}
		}
		
		if (n == 0 && m == 0) break;
		
		for (i = 1; i <= m; i++){
			scanf("%d %d", &a, &b);
			student[a][b]++;
			student[b][a]++;
			if (a == 1){
				friends[b] = 1;
			}
		}
		for (i = 1; i <= n; i++){
			for (j = 2; j <= n; j++){
				if (student[1][i] == 1 && student[i][j] == 1){
					friends[j] = 1;
				}
			}
		}
		for (i = 2; i <= n; i++){
			if (friends[i] == 1){
				invite++;
			}
		}
		printf("%d\n", invite);
	}
	return (0);
}
