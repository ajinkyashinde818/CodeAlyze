#include<stdio.h>

int main(){
	int k, n;
	int a[200005] = {0};
	int min;
	int i;

	scanf("%d %d", &k, &n);
	for(i=0; i<n; i++){
		scanf("%d", a+i);
	}

	min = k - (k - a[n-1]) - a[0];
	for(i=1; i<n; i++){
		if(k - (a[i]- a[i-1]) < min){
			min = k - (a[i] - a[i-1]);
		}
	}

	printf("%d", min);

	return 0;
}
