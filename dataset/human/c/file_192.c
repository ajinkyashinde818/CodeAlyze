#include <stdio.h>
int main(void){
	int n, num[100000] = {0}, minus = 0, min = 1000000000;
	long long ans = 0;
	scanf("%d", &n);getchar();
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);getchar();
		if(num[i] < 0){
			minus++;
			num[i] *= -1;
		}
		if(num[i] < min){
			min = num[i];
		}
	}
	if(minus % 2 == 0){
		for(int i = 0; i < n; i++){
			ans += num[i];
		}
		printf("%lld\n", ans);
	}else{
		for(int i = 0; i < n; i++){
			ans += num[i];
		}
		printf("%lld\n", ans - 2 * min);
	}
	return 0;
}
