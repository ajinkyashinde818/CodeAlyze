#include<stdio.h>
#define Max 200000
#define Min -2000000000;

int main(){
	int i;
	long R[Max];
	long n;
	long max, min;
	scanf("%ld", &n);

	for(i = 0; i < n; i++)
		scanf("%ld", &R[i]);
	max = Min;
	min = R[0];
	for(i = 1; i < n; i++) {
		max = max > R[i] - min ? max : R[i] - min;
		min = min < R[i] ? min : R[i]; 
	}

	printf("%ld\n", max);
    return 0;
}
