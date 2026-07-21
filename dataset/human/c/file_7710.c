#include <stdio.h>

int main(){
	int x[1000001];
	int i, j;
	for(i = 0; i <= 1000000; i++){
		scanf("%d", &x[i]);
		if(x[i] == 0){
			break;
		}
	}
	for(j = 0; j <= i-1; j++){
		printf("Case %d: %d\n", j+1, x[j]);
	} 
	return 0;
}
