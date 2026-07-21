#include<stdio.h>
long gcd(long a, long b){
	if(a == 0){
		return b;
	}
	else if(b == 0){
		return a;
	}
	else if(a<b){
		return gcd(a, b%a);
	}
	else if(a>b){
		return gcd(b, a%b);
	}
	else{
		return a;
	}
}

int main(void){
	long a, b;
	long x = 0;
	scanf("%ld", &a);
	scanf("%ld", &b);
	if(a == 0 || b == 0){
		x = 0;
	}
	else{
		x = a*b/gcd(a,b);
	}
	printf("%ld\n", x);
	return 0;
}
