#include <stdio.h>
#include <string.h>

int main(void)
{
	char list[501][501];
    char friend[501];
    char second[501];
    int n, m;
    int i, j;
    int from, to;
    int ans;
    
    while (1){
	    scanf("%d", &n);
   		scanf("%d", &m);
    	
		if (m + n == 0){
			break;
		}
		
    	memset(list, 0, sizeof(list));
    	
    	for (i = 0; i < m; i++){
        	scanf("%d%d", &from, &to);
        	list[from][to] = list[to][from] = 1;
    	}
    	
   		memset(friend, 0, sizeof(friend));
    	friend[1] = 1;
    	
    	for (i = 2; i <= n; i++){
        	if (list[1][i] == 1){
            	friend[i] = 1;
        	}
    	}
    	
    	memset(second, 0, sizeof(second));
    	for (i = 2; i <= n; i++){
        	for (j = 2; j <= n; j++){
            	if (list[i][j] == 1 && friend[i] == 1 && friend[j] != 1 && second[i] != 1){
                	friend[j] = 1;
               		second[j] = 1;
            	}
        	}
    	}
    	
    	ans = 0;
    	for (i = 2; i <= n; i++){
        	if (friend[i] == 1){
            	ans++;
        	}
    	}
    	
    	printf("%d\n", ans);
    }
	
    return (0);
}
