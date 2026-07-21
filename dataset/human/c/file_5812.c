#include <stdio.h>

int main(void){
	int n, i, j;
	int min;
	int max;
	scanf("%d",&n);
	int a[n];

	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}

	min = a[0];
	max = -2147483648;
	for(i = 1; i < n; i++){
		if(a[i] - min > max) max = a[i] - min;
		if(min > a[i]) min = a[i];
	}

	printf("%d\n", max);

	return 0;
}
