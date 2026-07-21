#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define P 1000000007

int comp(const void *a, const void *b){return *(int*)a-*(int*)b;}

int main(void){
	long n;
	scanf("%ld", &n);
	if(n&1!=0){
		puts("0");
	}else{
		n/=2;
		long ans=0;
		while(n>=5){
			n/=5;
			ans+=n;
		}
		printf("%ld\n", ans);
	}
}
