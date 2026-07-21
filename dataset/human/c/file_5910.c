#include <stdio.h>

int main(void){
	
	int n,r,num_min;
	int fin_max = -1000000000;
	
	scanf("%d", &n);
	scanf("%d", &num_min);
	for(int i = 0; i < n-1; i++){
		scanf("%d", &r);
		if( r-num_min > fin_max ) fin_max = r-num_min;
		if( r < num_min ) num_min = r;
	}
	printf("%d\n", fin_max);
	
}
