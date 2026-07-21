#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	
	int *array = malloc(sizeof(int)*n);
	
	int i;
	for(i=0;i<n;i++) {
		scanf("%d", array+i);
	}
	
	int max = -1.0e9;
	int min = *array;
	
	for(i=1;i<n;i++) {
		if(*(array+i)-min > max) {
			max = *(array+i)-min;
		}
		if(*(array+i) < min) {
			min = *(array+i);
		}
	}
	
	printf("%d\n", max);
	
	free(array);
	
	return 0;
}
