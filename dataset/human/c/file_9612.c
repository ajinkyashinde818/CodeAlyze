#include <stdio.h>

int main(void)
{
	int n, m;
	char N[100][10];
	int M[100];
	char T[10];
	int sum;
	int i, j, k;
	
	while (1){
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0){
			break;
		}
		
		for (i = 0; i < n; i++){
			scanf("%s", N[i]);
			scanf("%d", &M[i]);
		}
		
		sum = 0;
		for (i = 0; i < m; i++){
			scanf("%s", T);
			for (k = 0; k < n; k++){
				for (j = 0; j < 8; j++){
					if (N[k][j] != '*'){
						if (N[k][j] != T[j]){
							break;
						}
					}
				}
				if (j == 8){
//printf("[%s]", N[k]);
					sum += M[k];
				}
			}
		}
		
		printf("%d\n", sum);
	}
	return (0);
}
