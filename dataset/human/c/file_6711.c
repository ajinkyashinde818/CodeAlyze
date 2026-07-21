#include <stdio.h>
#include <string.h>

int main(void)
{
	int flag[501];
	int list[2][10000];
	int i, j;
	int n, m;
	int count;
	
	while (1){
		scanf("%d %d", &n, &m);
		
		if (!n && !m){
			break;
		}
		
		memset(flag, 0, sizeof(flag));
		
		for (i = 0; i < m; i++){
			scanf("%d %d", &list[0][i], &list[1][i]);
			
			if (list[0][i] == 1 || list[1][i] == 1){
				flag[list[0][i]] = flag[list[1][i]] = 100000;
			}
		}
		
		for (i = 0; i < m; i++){
			if (flag[list[0][i]] >= 100000 || flag[list[1][i]] >= 100000){
				flag[list[0][i]]++;
				flag[list[1][i]]++;
			}
		}
		
		count = 0;
		for (i = 2; i <= n; i++){
			if (flag[i]){
				count++;
				
			}
		}
		
		printf("%d\n", count);
	}
	
	return (0);
}
