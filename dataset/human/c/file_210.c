#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(void){
	int count = 0;
	int n;
	scanf("%d", &n);
	int *a = malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		if(a[i] < 0){
			count++;
			a[i] *= -1;
		}
	}
	qsort(a, n, sizeof(int), cmp);
	long sum = 0;
	int i = 0;
	if(count % 2){
		sum -= a[i];
		i++;
	}
	for(; i < n; i++){
		sum += a[i];
	}
	printf("%ld\n", sum);
	return 0;
}
