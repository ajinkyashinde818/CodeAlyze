#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

long _gcd(long  b,long r);

int main(void) {

	long    A,B;

	scanf("%ld %ld",&A,&B);

	if(A>B) printf("\n %lld",(long long)A*B/_gcd(A,B));
	else    printf("\n %lld",(long long)A*B/_gcd(B,A));

	return 0;
}

// 最大公約数
long _gcd(long b,long r) {
	if(!r) return(b);
	return (_gcd(r,b%r));
}
