#include <stdio.h>

#define MAX 200000
#define MIN -2000000000

int maxv( int a, int b )
{
	if ( a > b ) {
		return a;
	} else {
		return b;
	}
}

int minv( int a, int b )
{
	if ( a > b ) {
		return b;
	} else {
		return a;
	}
}

int main()
{
	int n = 0, i = 0, max = MIN, min;
	int val[MAX];

	scanf( "%d", &n );

	while( i < n ) {
		scanf( "%d", &val[i] );
		i++;
	}

	min = val[0];
	for ( int j = 1 ; j < n ; j++ ) {
		max = maxv( max, val[j] - min );
		min = minv( min, val[j] );
	}

	printf( "%d\n", max );
	return 0;
}
