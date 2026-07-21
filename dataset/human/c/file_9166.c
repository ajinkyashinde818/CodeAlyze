#include<stdio.h>
#include<stdlib.h>

int main(void){
	int n;
	scanf("%d",&n);

	int k;
	scanf("%d",&k);

	int h[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&h[i]);
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(h[i] >= k){
			ans += 1;
		}
	}

	printf("%d", ans);

	return 0;
}
