#include <stdio.h>

int main(){

	int n, max, min, i;
	int R[200000];

	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &R[i]);
	}

	max = R[1] - R[0];
	min = R[0];

	for(i=1; i<n; i++){
		if(R[i]-min>max){
			max = R[i] - min;
		}
		if(R[i]<min){
			min = R[i];
		}
	}

	printf("%d\n", max);

	return 0;
}
