#include <stdio.h>

int main(void){
	int n, m, tmp;
	int bibs[101] = {}, num[101] = {};
	int i, j, k;
	
	scanf("%d %d", &n, &m);
	
	for (i = 0; i < n; i++) scanf("%d", &bibs[i]);
	
	for (i = 1; i <= m; i++){
		for (j = 0; j < n; j++) num[j] = bibs[j]%i;
		
		for (j = 0; j < n-1; j++){
			if (num[j] > num[j+1]){
				tmp = num[j+1];
				num[j+1] = num[j];
				num[j] = tmp;
				
				tmp = bibs[j+1];
				bibs[j+1] = bibs[j];
				bibs[j] = tmp;
			}
		}
	}
	
	for (i = 0; i < n; i++) printf("%d\n", bibs[i]);
	
	return 0;
}
