#include <stdio.h>

int main(void){
	int N, K;
	int ans = 0;
	
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++){
		int height;
		scanf("%d", &height);
		if(height >= K) ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
