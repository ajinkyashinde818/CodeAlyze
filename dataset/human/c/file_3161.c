#include<stdio.h>
#include<stdlib.h>
int main(void){
	int k, n;
	int *a;
	int max_length = 0;
	scanf("%d", &k);
	scanf("%d", &n);
	a = (int *)malloc(sizeof(int) * n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	if(a[n-1] - a[0] <= k/2){
		printf("%d\n", a[n-1] - a[0]);
	}
	else{
		max_length = k - (a[n-1] - a[0]);
		for(int i=0; i<n-1; i++){
			if(a[i+1]-a[i] > max_length){
				max_length = a[i+1]-a[i];
			}
		}
		printf("%d\n", k - max_length);
	}
	return 0;
}
