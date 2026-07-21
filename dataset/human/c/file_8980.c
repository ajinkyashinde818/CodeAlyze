#include<stdio.h>

int main(){
	int d;
	int ans = 0;
	while(scanf("%d", &d) != 0){
		if(d == 0) break;
		while(d != 1){
			if(d % 2 == 0){
				d /= 2;
			}else{
				d = d * 3 + 1;
			}
			ans++;
		}
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}
