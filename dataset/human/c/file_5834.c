#include <stdio.h>
#define N 200000

int main(void) {
	int max,min, i ,j, n;
	scanf("%d" ,&n);
	int R[N];
	
	for(i = 0;i < n;i++){
		scanf("%d" , &R[i]);
	}
	
	max = R[1] - R[0];
	min = R[0];
	
	for(i = 1; i < n ;i++){
		if(max < R[i] - min){
		max = R[i] - min;
		}
		if(min > R[i]){
		min = R[i];
		}
	}

	printf("%d\n" , max);
	
	return 0;
}
