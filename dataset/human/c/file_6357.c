#include <stdio.h>
int main(void){
	int n,i,j,minv,maxv;
	scanf("%d" ,&n);
	int A[n];
	for(i = 0; i < n; i++){
		A[i] = 0;
	}
	for(i = 0; i < n; i++){
		scanf("%d" ,&A[i]);
	}
	minv = A[0];
	maxv = A[1] - A[0];
	for(j = 1; j <= n - 1; j++){
		if(maxv > A[j] - minv){
			maxv = maxv;
		}
		else if(maxv <= A[j] - minv){
			maxv = A[j] - minv;
		}
		if(minv > A[j]){
			minv = A[j];
		}
		else if(minv <= A[j]){
			minv = minv;
		}
	}
	printf("%d\n" ,maxv);
	return 0;
}
