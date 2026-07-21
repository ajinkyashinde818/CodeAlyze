#include <stdio.h>

int f[550][550];
int p[550], ans[550];

int main(void)
{
	int i, n, m;
	int a, b, j, sum;
	
	while (1){
		scanf("%d %d", &n, &m);
		
		if (n == 0 && m == 0){
			break;
		}
		for (i = 0; i < n; i++){
			p[i] = 0;
			ans[i] = 0;
			for (j = 0; j < 510; j++){
				f[i][j] = 0;
			}
		}
		for (i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			f[a - 1][b - 1] = 1;
			if (a == 1){
				p[b - 1] = 1;
				ans[b - 1] = 1;
			}
		}
		sum = 0;
		
		for (i = 1; i < n; i++){
			for (j = 1; j < n; j++){
				if ((p[i] == 1) && (f[i][j] == 1 || f[j][i] == 1)){
					ans[j] = 1;
				}
			}
		}
		for (i = 0; i < n; i++){
			sum += ans[i];
		}
		printf("%d\n", sum);
	}
	return (0);
}
