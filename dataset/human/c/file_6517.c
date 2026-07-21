#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int *R = NULL;
	int i,j;
	int max = - 1000000000;
	int min;
	int temp;
	scanf("%d",&n);
	R = (int *)malloc(4*n);
	for(i=0;i<n;i++){
		scanf("%d",&R[i]);
	}
	min = R[0];
	for(j=1;j<n;j++){
		temp = R[j] - min;
		if(temp > max){
			max = temp;
		}
		if(R[j] < min){
			min = R[j];
		}
	}
	printf("%d\n",max);
	free(R);
	return 0;
}
