#include <stdio.h>
#define DEBUG

int main(void){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int b[n];
	for(int i = 0; i < n; i++){
		b[i] = 0;
	}
	b[0] = 1;
	int i = 1;
	int ans = 0;
	while(1){
		ans++;
		i = a[i-1];
		if(i == 2){
			break;
		}
		if(b[i-1] > 1){
			printf("-1\n");
			return 0;
		}
		b[i-1]++; 
	}
	printf("%d\n", ans);
	return 0;
}
