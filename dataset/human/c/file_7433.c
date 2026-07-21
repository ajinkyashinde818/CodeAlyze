#include <stdio.h>

int main(void) {
	int x[10000], i = 0, cnt;
	while(1){
		scanf("%d", &x[i]);
		if(x[i] == 0){
			break;
		}else{
			i++;
			cnt++;
		}
	}
	for(i = 1; i <= cnt; i++){
		printf("Case %d: %d\n",i, x[i - 1]);
	}
	return 0;
}
