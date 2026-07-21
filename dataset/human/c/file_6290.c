#include <stdio.h>


int main(void){
	int R[200000];
	int n, i, j;
	int max = -999999999;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &R[i]);
	}
	int min = R[0];
	for(j=1;j<n;j++){
		if(R[j]-min>max)
			max = R[j]-min;
		if(min > R[j])
			min = R[j];
	}
	printf("%d\n", max);
	return 0;
}
