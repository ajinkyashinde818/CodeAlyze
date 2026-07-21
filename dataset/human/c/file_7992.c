#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define P 1000000007

long p(long a, long x){
	if(x==1){
		return a;
	}else if(x%2==0){
		long b = p(a, x/2);
		return (b*b)%P;
	}else{
		long b = p(a, x/2);
		return (((b*b)%P)*a)%P;
	}
}

long m(long a){
	return p(a, P-2);
}

long g(long a){
	long b=1;
	while(a>0){
		b = b*(a--)%P;
	}
	return b;
}

int main(void){
	int x, y, i, j;
	scanf("%d%d", &x, &y);
	if((x+y)%3!=0){
		puts("0");
	}else{
		int a = (x+y)/3;
		int b = (a+x-y)/2;
		int c = (a+y-x)/2;
		if(b<0 || c<0){
			puts("0");
		}else{
			printf("%d\n", g(a)*m(g(b))%P*m(g(c))%P);
		}
	}
}
