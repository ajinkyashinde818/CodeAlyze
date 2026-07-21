#include <stdio.h>

const int MAX = 200000;

int main( void ) {
	int i,n,min;
	int max = -1000000000;
	int rt[MAX];

	scanf( "%d", &n );
	for( i = 0; i < n; i++ ) scanf( "%d", &rt[i] );

	min = rt[0];
	for( i = 1; i < n; i++ ) {
		if ( max < (rt[i] - min) ) max = rt[i] - min;
		if ( min > rt[i] ) min = rt[i];
	}

	printf( "%d\n", max );

	return 0;
}
