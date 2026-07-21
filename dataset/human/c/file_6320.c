#include<stdio.h>

int main(void){
	int n,i, j;
	int a[200000];
	int ri,rj ,max, min;
	scanf("%d", &n);
	
	for(i = 0;i<n;i++){
		scanf("%d", &a[i]);
	}

	max = a[1]-a[0];
	min = a[0];
	for(j =1;j<n;j++){
		if(max < (a[j] -min)){
			max = a[j]-min;}
		if(min > a[j]){
			min = a[j];}
	}
	
	printf("%d\n", max);
	return 0;
}
