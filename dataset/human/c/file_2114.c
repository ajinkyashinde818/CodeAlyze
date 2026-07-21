#include <stdio.h>
#include <limits.h>

int main() {
	long n,count,x,i;
	scanf("%ld",&n);
	if(n&1) {
		printf("0");
		return 0;
	}
	count=0;
	x=10;
	while(n>=x){
		count+=(n/x);
		if(x>(LONG_MAX/5)) {
			break;
		}
		x*=5;
	}
	printf("%ld",count);
	return 0;
}
