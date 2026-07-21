#include <stdio.h>
#include <math.h>
#define SIZE 1000000
int prime[SIZE];

int sosu ( int n ) {
	int i , lim = (int)(sqrt(n));
	for ( i = 2; i <= lim; i++ ) {
		if ( n % i == 0 ) return 0;
	}
	return 1;
}

void tmp(void) {
	int i;
	prime[0] = prime[1] = 0;
	for ( i = 2; i < SIZE; i++ ) {
		prime[i] = sosu(i);
	}
	return;
}

int main (void) {
	int n , i;
	tmp();
	
	while ( 1 ) {
		int sum = 0;
		scanf("%d",&n);
		if ( n == 0 ) break;
		for ( i = 2; n > 0; i++ ) {
			if ( prime[i] ) {
				sum += i;
				n--;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
