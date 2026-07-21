/*ALDS1_1D: Maximum Profit*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define N 200000

int main(void){
	int R[N] = {0}, i = 0, n, minv, maxv;

	scanf("%d", &n);

	while(i < n){
		scanf("%d", &R[i++]);
	}

	minv = R[0];
	maxv = R[1] - R[0];
	for(i = 1; i < n - 1; i++){
		if(R[i] < minv){
			minv = R[i];
		}
		if(maxv < R[i+1] - minv) {
			maxv = R[i+1] - minv;
		}
	}

	printf("%d\n", maxv);

	return 0;
}
