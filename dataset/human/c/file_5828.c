#include<stdio.h>

int main(){
	int i, maxv, minv, n;
	int R[200000];
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &R[i]);
	}
	
	minv = R[0];
	maxv = -2000000000;
	
	for(i = 1; i < n; i++){
		if(maxv < R[i] - minv){
			maxv = R[i] - minv;
		}
		if(R[i] < minv){
			minv = R[i];
		}
	}
	
	printf("%d\n", maxv);
	
	return 0;
}
