#include<stdio.h>

int main( void ){
	
	int n;
	int i;
	int max , min;
	
	scanf( "%d" , &n );
	int r[n];
	
	for( i = 0; i < n; i++ ){
		scanf( "%d" , &r[i] );
	}
	
	max = r[1]-r[0];
	min = r[0];
	
	for( i = 1; i <= n - 1; i++ ){
		
		if( max < r[i] - min ){
			max = r[i] - min;
		}
		if( r[i] < min ){
			min = r[i];
		}
	}
	
	printf( "%d\n" , max );
	
}
