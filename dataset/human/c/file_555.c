#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
	int n, i;
	long b[200001];
	scanf("%d", &n);
	long s=0;
	for(i=0; i<n; i++){
		int a;
		scanf("%d", &a);
		s+=a;
		b[i]=s;
	}
	long min=INT_MAX;
	for(i=0; i<n-1; i++){
		long now = s-b[i]*2;
		if(now<0) now=-now;
		if(now<min) min=now;
	}
	printf("%ld\n", min);
}
