#include <stdio.h>
#include <stdlib.h>

int main(){
	int R, G, B, N, i, j, ans = 0;
	scanf("%d%d%d%d", &R, &G, &B, &N);
	for(i = 0; i <= N; i++){
		for(j = 0; j <= N; j++){
			int a = R * i + G * j;
			if(a <= N && (N - a) % B == 0){
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
