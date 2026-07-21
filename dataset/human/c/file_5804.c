#include <stdio.h>
#include <limits.h>

int main(void){
	int i, j, n, min = 0, max;
	int Rt[200000];
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d", &Rt[i]);
	}
	
	min = Rt[1];
	max = Rt[2] - Rt[1];
	for(i = 2; i <= n; i++){
		if(max < Rt[i] - min){
			max = Rt[i] - min;
		}
		if(min > Rt[i]){
			min = Rt[i];
		}
	}

	printf("%d\n", max);
	return 0;
}
