#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int comp(const void *a, const void *b){return *(int*)a-*(int*)b;}

int main(void){
	long x;
	scanf("%ld", &x);
	long ans = x/11*2;
	char i = x%11;
	if(i>=7) ans+=2;
	else if(i>=1) ans++;
	printf("%ld\n", ans);
}
