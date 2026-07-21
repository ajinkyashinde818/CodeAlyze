#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int cmp(const void *a,const void *b){
	return *((long *)b)-*((long *)a);
}

int main(){
	int n;
	scanf("%d",&n);
	long a[3*n];
	int i;
	
	for(i=0;i<3*n;i++){
		scanf("%ld",a+i);
	}
	
	qsort(a,3*n,sizeof(long),cmp);
	
	long long int total=0;
	for(i=0;i<n;i++){
		total+=a[i*2+1];
	}
	
	printf("%lld\n",total);
	
    return 0;
}
