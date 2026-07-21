#include <stdio.h>

#define MAX_N 104729

int isPrime[ MAX_N + 1 ] = { 0, 0, 1 };
int sum_p[ MAX_N / 2 ] = { 2 }, p = 1;

int main( void ) {
	int i, j, n, sum;

	for ( i = 3; i <= MAX_N; i += 2 )
		isPrime[ i ] = 1;

	for ( i = 3; i * i <= MAX_N; i += 2 )
		if ( isPrime[ i ] )
			for ( j = i * 2; j <= MAX_N; j += i )
				isPrime[ j ] = 0;

	sum = 2;
	for ( i = 3; i <= MAX_N; i += 2 )
		if ( isPrime[ i ] )
			sum_p[ p++ ] = sum += i;

	for ( ; scanf( "%d", &n ), n; printf( "%d\n", sum_p[ n - 1 ] ) ) ;

	return 0;
}
