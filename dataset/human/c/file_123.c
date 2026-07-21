#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int r, g, b, n, i, j, k, ans = 0;
	
	scanf("%d %d %d %d", &r, &g, &b, &n);
	
	for(i = 0; i * r <= n; i++){
		for(j = 0; i * r + j * g <= n; j++){
			if((n - (i * r + j * g)) % b == 0)
				ans++;
		}
	
	}
	
	printf("%d", ans);
	
}
