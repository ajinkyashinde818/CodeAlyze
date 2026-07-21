#include<stdio.h>

#define MAX_N 100

int n;
int p[MAX_N];

int main(void)
{
	int cnt, i, j;
	
	scanf( "%d", &n );
	
	for( i=0; i<n; i++ ) {
		scanf( "%d", &p[i] );
	}
	
	for( i=1; ; i++ ) {
	
		cnt = 0;
		for( j=0; j<n; j++ ) {
			if ( p[j] >= i ) cnt++;
		}
		
		if ( cnt < i ) break;
	}
	
	printf( "%d\n", i-1 );
	
	return 0;
}
