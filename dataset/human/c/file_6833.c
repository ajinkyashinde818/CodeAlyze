#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define P 1000000007

int comp(const void *a, const void *b){return *(int*)a-*(int*)b;}

int main(void){
	int n, i;
	int a[300000];
	scanf("%d", &n);
	for(i=0; i<n*3; i++){
		scanf("%d", a+i);
	}
	qsort(a, n*3, sizeof(int), comp);
	long ans=0;
	for(i=n; i<n*3; i+=2){
		ans+=a[i];
	}
	printf("%ld\n", ans);
}
