#include<stdio.h>

int main(void)
{
	int n, i, min, max;
	scanf( "%d", &n );
	int r[n];
	for( i = 0; i < n; i++ ){
		scanf( "%d", &r[i] );
	}
	
	max = r[1] - r[0];
	min = r[0];
	
	for( i = 1; i < n; i++ ){
		if( min > r[i] ){
			min = r[i];
		}else if( max < r[i] - min ){
			max = r[i] - min;
		}
	}
			
	printf( "%d\n", max );
	
	return 0;
}
